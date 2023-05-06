#pragma once

#include "../Core/Window.h"
#include <GLFW/glfw3.h>

namespace Razor
{
	class RZGLFWWindow : public Window
	{
	public:
		RZGLFWWindow(WindowData windowData);
		virtual ~RZGLFWWindow();

		void Update() override;

	private:
		GLFWwindow* m_glfwWindow;
	};
}

