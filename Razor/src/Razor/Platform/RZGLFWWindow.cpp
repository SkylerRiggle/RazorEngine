#include "RZGLFWWindow.h"

using namespace Razor;

RZGLFWWindow::RZGLFWWindow(WindowData windowData)
{
	// Initialize the GLFW library
	int initResult = glfwInit();
	ASSERT(initResult);

	// Create the new window
	glfwWindow = glfwCreateWindow(windowData.screenWidth, windowData.screenHeight, windowData.title, NULL, NULL);
	ASSERT(glfwWindow != nullptr)
	this->windowData = windowData;

	// Make the window's current context
	glfwMakeContextCurrent(glfwWindow);
}

RZGLFWWindow::~RZGLFWWindow()
{
	// Terminate the GLFW library
	glfwTerminate();
}

void RZGLFWWindow::Update()
{
	// Poll window events
	glfwPollEvents();

	// Swap the window buffers
	glfwSwapBuffers(glfwWindow);
}
