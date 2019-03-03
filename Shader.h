#pragma once
#define GLEW_STATIC // This must be defined when statically linking to GLEW
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <stdio.h>
#include <string>



class Shader
{
public:
	Shader();

	void AddShader(GLuint theProgram, const char* shaderCode, GLenum shaderType);
	void CompileShader(const char* vShader, const char* fragmentShader);

	GLuint GetProjectionLocation();
	GLuint GetModelLocation();
	GLuint GetProgramID();

	void UseShader();

	~Shader();
private:

	GLuint shaderID, uniformProjection, uniformModel;

	
};

