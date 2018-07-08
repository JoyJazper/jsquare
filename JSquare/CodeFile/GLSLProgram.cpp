#include"GLSLProgram.h"


GLSLProgram::GLSLProgram() : _ProgramID(0), _VertShaderID(0), _FragShaderID(0)
{
}

GLSLProgram::~GLSLProgram()
{
}


void GLSLProgram::compileShaders(const std::string& vertShaderFilePath, const std::string& fragShaderFilePath)
{
	_VertShaderID = glCreateShader(GL_VERTEX_SHADER);
}
void GLSLProgram::linkShaders()
{
	
}
