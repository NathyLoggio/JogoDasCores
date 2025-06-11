#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

class Sprite
{
public:
    GLuint VAO;
    GLuint texture;
    GLuint shader;
    glm::vec3 position;
    glm::vec3 scale;
    float rotation;

    Sprite(GLuint vao, GLuint tex, GLuint sh, glm::vec3 pos, glm::vec3 scale, float rotation);

    void draw(const glm::mat4 &projection);
};