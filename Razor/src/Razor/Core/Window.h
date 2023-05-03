#pragma once

#include <GLFW/glfw3.h>

namespace Razor
{
	/// <summary>
	/// The application's graphical window.
	/// </summary>
	class Window
	{
	public:
		/// <summary>
		/// Create a new application window.
		/// </summary>
		/// <param name="title">The title for the window.</param>
		/// <param name="defaultWidth">The default screen width.</param>
		/// <param name="defaultHeight">The default screen height.</param>
		Window(const char* title, const int defaultWidth, const int defaultHeight);
		~Window();

		/// <summary>
		/// Poll window events and swap window buffers.
		/// </summary>
		void Update();

		/// <summary>
		/// Returns the screen's current width.
		/// </summary>
		/// <returns>The screen's current width.</returns>
		inline int GetScreenWidth() { return this->screenWidth; }

		/// <summary>
		/// Returns the screen's current height.
		/// </summary>
		/// <returns>The screen's current height.</returns>
		inline int GetScreenHeight() { return this->screenHeight; }

	private:
		GLFWwindow* glfwWindow;
		int screenWidth, screenHeight;
	};
}