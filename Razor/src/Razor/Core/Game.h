#pragma once

#include "../Core.h"
#include "Window.h"

namespace Razor
{
	/// <summary>
	/// All of the introductory game metadata. 
	/// </summary>
	struct GameData 
	{
	public:
		WindowData windowData;
	};

	/// <summary>
	/// A class representing the overall game application.
	/// </summary>
	class RAZOR_API Game
	{
	public:
		/// <summary>
		/// Create a new game application.
		/// </summary>
		/// <param name="gameData">The game's default data.</param>
		Game(GameData gameData);
		~Game();

		/// <summary>
		/// Start the game application.
		/// </summary>
		void StartGame();

		/// <summary>
		/// Signal the game application to close.
		/// </summary>
		static inline void CloseGame() { s_applicationRunning = false; }

	private:
		Window* m_window;
		static bool s_applicationRunning;
	};

	/// <summary>
	/// Create a new game application.
	/// </summary>
	/// <returns>A pointer to the new game application.</returns>
	Game* CreateGame();
}

