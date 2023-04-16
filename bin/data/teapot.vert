#version 330

uniform mat4x4 modelViewProjectionMatrix;

in vec4 position;
in vec2 texcoord;

out vec2 surface_texcoord;

void main()
{
    surface_texcoord = texcoord;
    gl_Position = modelViewProjectionMatrix * position;
}
