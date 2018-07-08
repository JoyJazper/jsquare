#include"Shader.h"
#include<iostream>
#include"../Utils/FileUtils.h"


namespace JSquare{
	namespace Graphics{
		using namespace utils;
		Shader::Shader(const char* vertPath, const char* fragPath)
		:m_VertPath(vertPath),m_FragPath(fragPath)
		{
			m_shaderID = load();
		}

		Shader::~Shader()
		{
			glDeleteProgram(m_shaderID);
		}

		GLuint Shader::load()
		{
			GLuint program = glCreateProgram();
			GLuint vertex = glCreateShader(GL_VERTEX_SHADER);
			GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);

			std::string vertSourceString = FileReader::ReadFile(m_VertPath);
			std::string fragSourceString = FileReader::ReadFile(m_FragPath);

			const char* vertSource = vertSourceString.c_str();
			const char* fragSource = fragSourceString.c_str();

			glShaderSource(vertex, 1, &vertSource, NULL);
			glCompileShader(vertex);

			GLint result;
			glGetShaderiv(vertex,GL_COMPILE_STATUS, &result);
			if(result == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(vertex, length, &length, &error[0]);
				std::cout<<"Failed to compile fragment Shader!"<<std::endl;
				std::cout<< &error[0] << std::endl;
				glDeleteShader(vertex);
				return 0;

			}

			glShaderSource(vertex, 1, &vertSource, NULL);
			glCompileShader(vertex);

			GLint result2;

			glGetShaderiv(fragment,GL_COMPILE_STATUS, &result2);
			if(result == GL_FALSE)
			{
				GLint length;
				glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
				std::vector<char> error(length);
				glGetShaderInfoLog(fragment, length, &length, &error[0]);
				std::cout<<"Failed to compile fragment Shader!"<<std::endl;
				std::cout<< &error[0] << std::endl;
				glDeleteShader(fragment);
				return 0;

			}

			glAttachShader(program, vertex);
			glAttachShader(program, fragment);

			glLinkProgram(program);
			glValidateProgram(program);

			glDeleteShader(vertex);
			glDeleteShader(vertex);
			return program;
		}


		void Shader::enable() const
		{
			glUseProgram(m_shaderID);
		}

		void Shader::disable() const
		{
			glUseProgram(0);
		}
	}
}