#version 330
layout(location = 0) in vec3 vertexPosition_modelspace;

uniform mat4 MVP;

void main(void)
{
//    gl_Position = projection * camera * model * vec4(vertexPosition, 1);
    gl_Position = MVP * vec4(vertexPosition_modelspace, 1.0);
//    color = vec3(1.0, 0.0, 0.0);
}
