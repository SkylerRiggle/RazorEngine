#include "Window.h"

using namespace Razor;

Window::Window(const char* title, const int defaultWidth, const int defaultHeight)
{
	// Initialize the GLFW library
	int initResult = glfwInit();
	ASSERT(initResult);

	// Create the new window
	glfwWindow = glfwCreateWindow(defaultWidth, defaultHeight, title, NULL, NULL);
	ASSERT(glfwWindow != nullptr)
	screenWidth = defaultWidth;
	screenHeight = defaultHeight;

	// Make the window's current context
	glfwMakeContextCurrent(glfwWindow);
}

Window::~Window()
{
	// Terminate the GLFW library
	glfwTerminate();
}

void Window::Update()
{
	// Poll window events
	glfwPollEvents();

	// Swap the window buffers
	glfwSwapBuffers(glfwWindow);
}