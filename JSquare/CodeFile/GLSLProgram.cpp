#include"GLSLProgram.h"
#include"ErrorC.h"
#include<vector>

GLSLProgram::GLSLProgram() : _ProgramID(0), _VertShaderID(0), _FragShaderID(0)
{
}

GLSLProgram::~GLSLProgram()
{
}


void GLSLProgram::compileShaders(const std::string& vertShaderFilePath, const std::string& fragShaderFilePath)
{
	_VertShaderID = glCreateShader(GL_VERTEX_SHADER);
	if (_VertShaderID == 0)
	{
		FatalError("Vertex Shader not created!!");
	}

	_FragShaderID = glCreateShader(GL_FRAGMENT_SHADER);
	if (_FragShaderID == 0)
	{
		FatalError("Fragment Shader not created!!");
	}

	std::ifstream VertexFile(vertShaderFilePath);
	if (VertexFile.fail())
	{
		perror(vertShaderFilePath.c_str());
		FatalError("vertex Shader not opened! file path :"+ vertShaderFilePath);
	}

	std::string fileContents = "";
	std::string line;

	while (std::getline(VertexFile, line))
	{
		fileContents += line + "/n";
	}

	VertexFile.close();

	const char* contentsPtr= fileContents.c_str();
	glShaderSource(_VertShaderID, 1, &contentsPtr, nullptr);
	
	GLuint success = 0;
	glCompileShader(_VertShaderID);
	glGetShaderiv(_VertShaderID, GL_COMPILE_STATUS, &success);
	if (success == GL_FALSE)
	{
		GLint maxLength = 0;
		glGetShaderiv(_VertShaderID, GL_INFO_LOG_LENGTH, &maxLength);

		// The maxLength includes the NULL character
		std::vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(_VertShaderID, maxLength, &maxLength, &errorLog[0]);

		// Provide the infolog in whatever manor you deem best.
		// Exit with failure.
		glDeleteShader(_VertShaderID); // Don't leak the shader.
		FatalError("Vertex Shader failed to compile.");
		return;
	}


	std::ifstream FragmentFile(fragShaderFilePath);
	if (FragmentFile.fail())
	{
		perror(fragShaderFilePath.c_str());
		FatalError("fragment Shader not opened! file path :" + fragShaderFilePath);
	}
}
void GLSLProgram::linkShaders()
{
	
}
