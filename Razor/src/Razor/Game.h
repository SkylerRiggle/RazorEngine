#pragma once

#include "Core.h"

namespace Razor
{
	struct GameData 
	{
	public:
		const char* title;
	};

	class RAZOR_API Game
	{
	public:
		Game(GameData gameData);
		~Game();

		void StartGame();
	};

	Game* CreateGame();
}

