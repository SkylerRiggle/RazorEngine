#pragma once

#include "../Core/Window.h"
#include "../Core/Game.h"
#include <GLFW/glfw3.h>

namespace Razor
{
	class RZGLFWWindow : public Window
	{
	public:
		RZGLFWWindow(WindowData windowData);
		virtual ~RZGLFWWindow();

		void Update() override;
		void SetVSync(bool enabled) override;

	private:
		/// <summary>
		/// Sets the window's event callback functions.
		/// </summary>
		void SetEventCallbacks();

		GLFWwindow* m_glfwWindow;
	};
}

