#include "Sprite.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GLFW/glfw3.h>

Sprite::Sprite(GLuint VAO, GLuint texture, GLuint shader, glm::vec3 position, glm::vec3 scale, float rotation,
               int framesX, int framesY, float fps)
    : VAO(VAO), texture(texture), shader(shader), position(position), scale(scale), rotation(rotation),
      framesX(framesX), framesY(framesY), currentFrame(0), currentRow(0), frameDuration(1.0f / fps), animTime(0.0)
{}

void Sprite::update(float deltaTime, int direction)
{
    currentRow = direction; // 0=baixo, 1=esquerda, 2=direita, 3=cima
    double timeNow = glfwGetTime();
    if (timeNow - animTime >= frameDuration)
    {
        currentFrame = (currentFrame + 1) % framesX;
        animTime = timeNow;
    }
}

void Sprite::move(float dx, float dy)
{
    position.x += dx;
    position.y += dy;
}

void Sprite::draw(const glm::mat4& projection)
{
    glUseProgram(shader);

    glBindVertexArray(VAO);
    glBindTexture(GL_TEXTURE_2D, texture);

    float ds = 1.0f / framesX;
    float dt = 1.0f / framesY;  
    float offsetX = currentFrame * ds;
    float offsetY = currentRow * dt;

    GLint offsetLoc = glGetUniformLocation(shader, "offset");
    GLint scaleLoc = glGetUniformLocation(shader, "scale");
    glUniform2f(offsetLoc, offsetX, offsetY);
    glUniform2f(scaleLoc, ds, dt);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);
    model = glm::scale(model, scale);

    glUniformMatrix4fv(glGetUniformLocation(shader, "model"), 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(glGetUniformLocation(shader, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}