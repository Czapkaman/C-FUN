#pragma once
#define GLEW_STATIC // This must be defined when statically linking to GLEW
#include <stdio.h>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "glm/glm.hpp"
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>

class Window
{
public:
	Window(GLuint width = 800, GLuint height = 600, const char* WindowName = "Undefine");
	~Window();

	bool ShouldClose() { return !glfwWindowShouldClose(mainWindow); }
	void swapBuffers() { glfwSwapBuffers(mainWindow); }
	void ClearColor(float R = 0.0f, float G = 0.0f, float B = 0.0f, float A = 1.0f );
	bool * getsKeys() { return keys; }
	const float * GetProjectionPtr() { return ProjectionPtr; }
private:
	// Window dimensions
	GLint WIDTH, HEIGHT;
	GLFWwindow *mainWindow;

	glm::mat4 projection;
	bool keys[512];
	void createCallbacks(); 
	static void handleKeys(GLFWwindow* window, int key, int code, int action, int mode);
	const float * ProjectionPtr = glm::value_ptr(projection);
	
};

