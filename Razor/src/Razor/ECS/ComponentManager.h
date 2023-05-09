#pragma once

#include "ComponentArray.h"

namespace Razor
{
	class ComponentManager
	{
	public:
		template<typename T>
		void RegisterComponentType()
		{

		}

		template<typename T>
		void AddComponent(Entity entity, T componentData)
		{

		}

		template<typename T>
		void RemoveComponent(Entity entity)
		{

		}

		template<typename T>
		T& GetComponent(Entity entity)
		{

		}
	};
}