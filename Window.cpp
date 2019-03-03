#include "Window.h"

Window::Window(GLuint width, GLuint height, const char* title)
{

	Window::HEIGHT = height;
	Window::WIDTH = width;

	projection = glm::ortho(0.0f, (float)width, 0.0f, (float)height, 0.0f, 1.0f);

	// Initialise GLFW
	if (!glfwInit())
	{
		printf("GLFW initialisation failed!");
		glfwTerminate();
		return;
	}

	// Setup GLFW window properties
	// OpenGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// Core Profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// Allow Forward Compatbility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// Create the window
	Window::mainWindow = glfwCreateWindow(width, height, title, NULL, NULL);
	if (!mainWindow)
	{
		printf("GLFW window creation failed!");
		glfwTerminate();
		return;
	}

	// Get Buffer Size information
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	// Set context for GLEW to use
	glfwMakeContextCurrent(mainWindow);
	
	// Keyboard
	createCallbacks();

	// Allow modern extension features
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("GLEW initialisation failed!");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return;
	}
	
	glfwSetWindowUserPointer(mainWindow, this);

	// Setup Viewport size
	glViewport(0, 0, bufferWidth, bufferHeight);
}

void Window::handleKeys(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Window* theWindow = static_cast<Window*>(glfwGetWindowUserPointer(window));

	if (theWindow == NULL)
	{
		printf("Pointer is NULL\n");
		return;
	}

	if (key >= 0 && key < 512)
	{
		if (action == GLFW_PRESS)
		{
			theWindow->keys[key] = true;
		}
		else if (action == GLFW_RELEASE)
		{
			theWindow->keys[key] = false;
		}
	}
}

void Window::createCallbacks()
{
	glfwSetKeyCallback(mainWindow , handleKeys);
}

void Window::ClearColor(float R, float G, float B, float A)
{
	// Clear window
	glClearColor(R, G, B, A);
	glClear(GL_COLOR_BUFFER_BIT);
}

Window::~Window()
{
	glfwDestroyWindow(Window::mainWindow);
	glfwTerminate();
}
