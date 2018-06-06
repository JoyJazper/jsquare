#include<iostream>
#include"Graphics/Window.h"
#include"Maths/mat4.h"
#include"Maths/maths_func.h"
#include"Maths/vec2.h"
#include"Maths/vec3.h"
#include"Maths/vec4.h"
int main()
{
	using namespace JSquare;
	using namespace Graphics;
	using namespace Maths;

	Window window("Jazper",800, 600);

	/*GLuint vao;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
*/
	/*vec4 a(0.2f, 0.3f, 0.8f, 1.0f);
	vec4 b(0.5f, 0.2f, 0.1f, 1.0f);
	*/
	mat4 position = mat4::Translate(vec3(2,3,4));

	//glClearColor(0.2f, 0.3f, 0.8f, 1.0f);
	while (!window.closed())
	{
		window.clear();
		double x, y;
		//window.getMousePosition(x, y);
		//std::cout << x << ", "<< y << std::endl;
		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();
		glDrawArrays(GL_ARRAY_BUFFER, 0, 6);
		window.update();
	}
	return(0);

}