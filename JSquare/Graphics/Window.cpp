#include<iostream>
#include"Window.h"
#include"glfw3.h"

namespace JSquare {
	namespace Graphics {

		Window::Window(const char *title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;
			init();
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		void Window::update()
		{
			std::cout << "Update is called!" << std::endl;
			glfwPollEvents();
			glfwGetFramebufferSize(m_Window, &m_Width, &m_Height);
			glfwSwapBuffers(m_Window);
		}

		bool Window::init()
		{
			glfwInit();
			if (!glfwInit)
			{
				std::cout << "Failed to Initialize!" << std::endl;
				return false;
			}
			else {
				std::cout << "Initialized glfw!" << std::endl;
			}
			glfwMakeContextCurrent(m_Window);
			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
			if (!m_Window)
			{
				std::cout << "Failed to load the window" << std::endl;
				return false;
			}
			else {
				std::cout << "Window online!" << std::endl;
			}
			
			return true;
		}
		
		void Window::clear() const {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window);
		}
			
	}
}