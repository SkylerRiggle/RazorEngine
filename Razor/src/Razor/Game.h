#pragma once

#include "Core.h"

namespace Razor
{
	class RAZOR_API Game
	{
	public:
		Game();
		virtual ~Game();

		void Main();
	};

	Game* CreateGame();
}

