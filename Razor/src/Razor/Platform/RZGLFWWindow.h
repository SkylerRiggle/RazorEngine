#pragma once

#include "../Core/Window.h"
#include "../Core/Assert.h"

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace Razor
{
	/// <summary>
	/// The GLFW application window.
	/// </summary>
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

