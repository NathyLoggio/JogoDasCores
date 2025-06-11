//iniciando com Sprite.h quais modificações precisa o meu código: 
#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

class Sprite {
public:
    GLuint VAO;
    GLuint texture;
    GLuint shader;
    glm::vec3 position;
    glm::vec3 scale;
    float rotation;

    // Animação
    int framesX, framesY;    // Quantos frames na horizontal e vertical no spritesheet
    int currentFrame;        // Frame atual (coluna)
    int currentRow;          // Linha atual (direção)
    float animTime;          // Acumulador de tempo para animação
    float frameDuration;     // Duração de cada frame (em segundos)

    Sprite(GLuint vao, GLuint tex, GLuint sh, glm::vec3 pos, glm::vec3 scale, float rotation,
           int framesX = 4, int framesY = 4, float fps = 8.0f);

    void draw(const glm::mat4& projection);
    void update(float delta, int direction); // direction: 0=baixo, 1=esq, 2=dir, 3=cima
    void move(float dx, float dy);
};