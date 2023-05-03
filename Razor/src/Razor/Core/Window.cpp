#include "Window.h"

using namespace Razor;

Window::Window()
{
	// Initialize the GLFW library
	int initResult = glfwInit();
	// TODO: Assert init succeeded

	// Create the new window
	glfwWindow = glfwCreateWindow(500, 500, "HELLO WORLD", NULL, NULL);
	// TODO: Assert window is created

	// Make the window's current context
	glfwMakeContextCurrent(glfwWindow);
}

Window::~Window()
{
	// Terminate the GLFW library
	glfwTerminate();
}