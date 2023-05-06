#include "RZGLFWWindow.h"

using namespace Razor;

RZGLFWWindow::RZGLFWWindow(WindowData windowData)
{
	// Initialize the GLFW library
	int initResult = glfwInit();
	ASSERT(initResult);

	// Create the new window
	m_glfwWindow = glfwCreateWindow(windowData.screenWidth, windowData.screenHeight, windowData.title, NULL, NULL);
	ASSERT(glfwWindow != nullptr)
	m_windowData = windowData;

	// Make the window's current context
	glfwMakeContextCurrent(m_glfwWindow);
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
	glfwSwapBuffers(m_glfwWindow);
}
