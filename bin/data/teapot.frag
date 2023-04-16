#version 330

uniform sampler2D tex0;

in vec2 surface_texcoord;

out vec4 fragment_color;

void main()
{
    vec3 color = texture2D(tex0, surface_texcoord).rgb;
    fragment_color = vec4(color, 1.0);
}
