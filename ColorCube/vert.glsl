#version 330
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec3 vertexNormal;
layout(location = 2) in vec3 vertexColor;

uniform mat4 MVP;

out vec3 color;

void main(void)
{
    gl_Position = MVP * vec4(vertexPosition_modelspace, 1.0);
    color = vertexColor;
}
