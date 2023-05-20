#pragma once

#include "./Core.h"

namespace Razor
{
	struct WindowData
	{
	public:
		const char* title;
		int screenWidth;
		int screenHeight;
		bool vSync;
	};

	/// <summary>
	/// The application's graphical window.
	/// </summary>
	class RAZOR_API Window
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
		/// Sets the window's vsync status.
		/// </summary>
		/// <param name="enabled">The new status for the window's vsync.</param>
		virtual void SetVSync(bool enabled) = 0;
		
		/// <summary>
		/// Returns whether the window currently has vsync on.
		/// </summary>
		/// <returns>Whether the window currently has vsync on.</returns>
		inline bool IsVSync() { return this->m_windowData.vSync; }

		/// <summary>
		/// Creates the appropriate application window.
		/// </summary>
		/// <param name="windowData">The default window data.</param>
		/// <returns>A reference to the newly created window.</returns>
		static Window* CreateWindow(WindowData windowData);

	protected:
		WindowData m_windowData{};
	};
}