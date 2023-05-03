#pragma once

#include <GLFW/glfw3.h>

namespace Razor
{
	class Window
	{
	public:
		Window();
		~Window();

	private:
		GLFWwindow* glfwWindow;
	};
}