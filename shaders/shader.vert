#version 400

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texc;

out vec2 tex_coord;

uniform mat4 model;
uniform mat4 projection;

// Define quantos frames por linha e por coluna (ex: 3x4)
uniform vec2 scale;     // tamanho de cada frame (1/nFrames, 1/nAnimations)
uniform vec2 offset;    // posição do frame atual (s, t)

void main()
{
    tex_coord = offset + texc * scale;  // calcula a coordenada do frame atual
    gl_Position = projection * model * vec4(position, 1.0);
}