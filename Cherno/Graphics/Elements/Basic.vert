#version 330 core

layout(location = 0) in vec4 position;

uniform mat4 pr_matrix;
uniform mat4 vm_matrix = mat4(1.0);
uniform mat4 ml_matrix = mat4(1.0);

void main()
{
	gl_position = /*pr_matrix*/ position;
}