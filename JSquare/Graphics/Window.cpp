#include<iostream>
#include"Window.h"

namespace JSquare {
	namespace Graphics {

		Window::Window(const char *title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;
			init();

			for (int i = 0; i < MAX_KEYS; i++)
			{
				m_Keys[i] = false;
			}

			for (int i = 0; i < MAX_BUTTONS; i++)
			{
				m_MouseButtons[i] = false;
			}
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		bool Window::isKeyPressed(unsigned int KeyCode) const {
			if (KeyCode >= MAX_KEYS)
			{
				return false;
			}
			return m_Keys[KeyCode];
		}

		bool Window::isMouseButtonPressed(unsigned int ButtonPress) const {
			if (ButtonPress >= MAX_BUTTONS)
			{
				return false;
			}
			return m_MouseButtons[ButtonPress];
		}


		void Window::getMousePosition(double& x, double& y) const {
			x = mx;
			y = my;
		}

		void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_Keys[key] = action != GLFW_RELEASE;
		}

		void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->m_MouseButtons[button] = action != GLFW_RELEASE;
		}

		void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
		{
			Window* win = (Window*)glfwGetWindowUserPointer(window);
			win->mx = xpos;
			win->my = ypos;
		}


		void Window::update()
		{
			//std::cout << "Update is called!" << std::endl;
			glfwPollEvents();
			glfwSwapBuffers(m_Window);
		}

		bool Window::init()
		{
			glfwInit();
			if (!glfwInit)
			{
				std::cout << "Failed to Initialize GLFW!" << std::endl;
				return false;
			}
			else {
				std::cout << "Initialized glfw!" << std::endl;
			}
			m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

			if (!m_Window)
			{
				std::cout << "Failed to load the window" << std::endl;
				std::cin.get();
				return false;
			}
			else {
				std::cout << "Window online!" << std::endl;
			}

			glfwMakeContextCurrent(m_Window);
			glfwSetWindowUserPointer(m_Window, this);
			glfwSetKeyCallback(m_Window, key_callback);
			glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
			glfwSetCursorPosCallback(m_Window, cursor_position_callback);
			glewInit();
			if (glewInit() != GLEW_OK)
			{
				std::cout << "Glew not initialized." << std::endl;
				return false;
			}
			else
			{
				std::cout << "Glew Initialized." << std::endl;
			}
	
			std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;

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