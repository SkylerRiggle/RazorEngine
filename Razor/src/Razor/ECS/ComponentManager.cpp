#include "ComponentManager.h"

using namespace Razor;

void ComponentManager::EntityDestroyed(Entity entity)
{
	for (auto const& pair : m_typeToArray)
	{
		auto const& componentArray = pair.second;
	}
}