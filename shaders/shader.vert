#version 330 core
layout (location = 0) in vec3 inPosition;
layout (location = 0) in vec3 inColor;

out vec3 ourColor;

void main()
{
    gl_Position = vec4(inPosition, 1.0);
    ourColor = inColor;
}
