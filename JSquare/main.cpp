#include<iostream>
#include"Graphics/Window.h"
#include<glfw3.h>


int main()
{
	using namespace JSquare;
	using namespace Graphics;

	glfwInit();
	Window window("Jazper",800, 600);

	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	while (!window.closed())
	{
		window.clear();
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		window.update();
	}
	return(0);

}