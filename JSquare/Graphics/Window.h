#pragma once

#include<iostream>
#include<glfw3.h>

namespace JSquare {
	namespace Graphics {

		class Window
		{
		private:
			int m_Width, m_Height;
			const char *m_Title;
			GLFWwindow *m_Window;
			bool m_Closed;
		public:
			Window(const char *title, int width, int height);
			~Window();
			bool closed() const;
			void update();
			void clear() const;
		private:
			bool init();

		};



	}
}