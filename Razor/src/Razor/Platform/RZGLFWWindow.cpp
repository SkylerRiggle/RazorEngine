#include "RZGLFWWindow.h"

using namespace Razor;

RZGLFWWindow::RZGLFWWindow(WindowData windowData)
{
	// Initialize the GLFW library
	int initResult = glfwInit();
	ASSERT(initResult);

	// Create the new window
	m_glfwWindow = glfwCreateWindow(windowData.screenWidth, windowData.screenHeight, windowData.title, NULL, NULL);
	ASSERT(m_glfwWindow != nullptr);
	m_windowData = windowData;
	glfwSetWindowUserPointer(m_glfwWindow, &m_windowData);

	// Set the window's callback functions
	SetEventCallbacks();

	// Set the window's default vsync status
	SetVSync(windowData.vSync);

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

void RZGLFWWindow::SetVSync(bool enabled)
{
	// Set and store the window's vsync status.
	glfwSwapInterval(enabled ? 1 : 0);
	m_windowData.vSync = enabled;
}

void RZGLFWWindow::SetEventCallbacks()
{
	// Resize callback
	glfwSetWindowSizeCallback(m_glfwWindow, [](GLFWwindow* window, int width, int height)
	{
			// Store the window's new width and height values
			WindowData& windowData = *(WindowData*)glfwGetWindowUserPointer(window);
			windowData.screenWidth = width;
			windowData.screenHeight = height;
	});

	// Close callback
	glfwSetWindowCloseCallback(m_glfwWindow, [](GLFWwindow* window)
	{
			// Close the game application
			Game::CloseGame();
	});
}
