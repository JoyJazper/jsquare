#pragma once
#include<vector>
#include<glew.h>

namespace JSquare{
	namespace Graphics{

		class Shader
		{
		private:
			GLuint m_shaderID;
			const char *m_VertPath;
			const char *m_FragPath;
		public:
			Shader(const char* vertPath, const char* fragPath);
			~Shader();

			void enable() const;
			void disable() const;
		private:
			GLuint load();
		};
	}
}