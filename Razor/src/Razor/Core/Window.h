#pragma once

#include <GLFW/glfw3.h>
#include "../Assert.h"

namespace Razor
{
	struct WindowData
	{
	public:
		const char* title;
		int screenWidth;
		int screenHeight;
	};

	/// <summary>
	/// The application's graphical window.
	/// </summary>
	class Window
	{
	public:
		virtual ~Window() = default;

		/// <summary>
		/// Update the window.
		/// </summary>
		virtual void Update() = 0;

		/// <summary>
		/// Returns the game's title.
		/// </summary>
		/// <returns>The game's title.</returns>
		inline const char* GetWindowTitle() { return this->m_windowData.title; }

		/// <summary>
		/// Returns the screen's current width.
		/// </summary>
		/// <returns>The screen's current width.</returns>
		inline int GetScreenWidth() { return this->m_windowData.screenWidth; }

		/// <summary>
		/// Returns the screen's current height.
		/// </summary>
		/// <returns>The screen's current height.</returns>
		inline int GetScreenHeight() { return this->m_windowData.screenHeight; }

		/// <summary>
		/// Creates the appropriate application window.
		/// </summary>
		/// <param name="windowData">The default window data.</param>
		/// <returns>A reference to the newly created window.</returns>
		static Window* CreateWindow(WindowData windowData);

	protected:
		WindowData m_windowData;
	};
}