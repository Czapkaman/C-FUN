#pragma once
#define GLEW_STATIC // This must be defined when statically linking to GLEW
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <stdio.h>
#include <string>
#include "Shader.h"
#include "glm/glm.hpp"


class Mesh
{
public:
	Mesh();
	~Mesh();
	void CreateSquare();
	void RenderSquare();


private:
	GLuint VBO =0 , VAO =0 , IBO = 0;
	unsigned int indexCount;
};

