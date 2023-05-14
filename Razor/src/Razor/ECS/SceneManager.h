#pragma once

#include "Scene.h"

namespace Razor
{
	class SceneManager
	{
	public:
		static inline Scene& GetActiveScene() { return *s_activeScene; }

	private:
		static Scene* s_activeScene;
	};
}

