#pragma once

#include "../Types.h"
#include "../Assert.h"
#include <unordered_map>

namespace Razor
{
	template<typename T>
	struct ComponentArray
	{
	public:
		std::array<T, MAX_ENTITIES> components{};
		std::unordered_map<Entity, size_t> entityToIndex{};
		std::unordered_map<size_t, Entity> indexToEntity{};
	};

	class ComponentManager
	{
	public:
		template<typename T>
		void RegisterComponent<T>();

		template<typename T>
		void AddComponent(Entity entity, T componentData);

		template<typename T>
		void RemoveComponent(Entity entity);

		template<typename T>
		T& GetComponent(Entity entity);
	};
}

