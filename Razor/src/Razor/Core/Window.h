#pragma once

#include <GLFW/glfw3.h>

namespace Razor
{
	class Window
	{
	public:
		Window(const char* title, const int defaultWidth, const int defaultHeight);
		~Window();

		void Update();

	private:
		GLFWwindow* glfwWindow;
	};
}