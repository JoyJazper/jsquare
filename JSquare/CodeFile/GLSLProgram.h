#pragma once
#include <string>
#include <glew.h>

class  GLSLProgram
{
public:
	 GLSLProgram();
	~ GLSLProgram();

	void compileShaders(const std::string& vertShaderFilePath, const std::string& fragShaderFilePath);
	void linkShaders();

private:
	GLuint _ProgramID;
	GLuint _VertShaderID;
	GLuint _FragShaderID;
};

