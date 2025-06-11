#include "Sprite.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

Sprite::Sprite(GLuint vao, GLuint tex, GLuint sh, glm::vec3 pos, glm::vec3 scale, float rotation)
    : VAO(vao), texture(tex), shader(sh), position(pos), scale(scale), rotation(rotation)
{}

void Sprite::draw(const glm::mat4 &projection)
{
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);
    model = glm::rotate(model, rotation, glm::vec3(0, 0, 1));
    model = glm::scale(model, scale);

    glUseProgram(shader);
    glBindVertexArray(VAO);
    glBindTexture(GL_TEXTURE_2D, texture);

    GLint modelLoc = glGetUniformLocation(shader, "model");
    GLint projLoc = glGetUniformLocation(shader, "projection");
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    glBindVertexArray(0);
    glUseProgram(0);
}