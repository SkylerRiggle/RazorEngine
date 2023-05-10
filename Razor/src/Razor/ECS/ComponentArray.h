#pragma once

#include "../Types.h"
#include <unordered_map>

namespace Razor
{
	struct IComponentArray
	{
	public:
		size_t size = 0;
	};

	template<typename T>
	struct ComponentArray : public IComponentArray
	{
	public:
		std::array<T, MAX_ENTITIES> components{};
		std::unordered_map<Entity, size_t> entityToIndex{};
	};
}