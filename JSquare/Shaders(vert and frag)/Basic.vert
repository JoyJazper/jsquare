#version 130

in vec2 vectorPosition;

void main()
{
	gl_Position.xy = vertexPosition;
	gl_Position.z = 0.0;
	gl_Position.xy = 1.0;
}
	