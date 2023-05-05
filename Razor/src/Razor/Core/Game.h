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
		Game(GameData gameData);
		~Game();

		/// <summary>
		/// Start the game application.
		/// </summary>
		void StartGame();

	private:
		Window* window;
	};

	/// <summary>
	/// Create a new game application.
	/// </summary>
	/// <returns>A pointer to the new game application.</returns>
	Game* CreateGame();
}

