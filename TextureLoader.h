#pragma once

#define GLEW_STATIC // This must be defined when statically linking to GLEW

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <stdio.h>


class TextureLoader
{
public:
	TextureLoader(const char* filelocation, const char* Type);
	void UseTexture();
	~TextureLoader();

private:
	GLuint texture;
};

