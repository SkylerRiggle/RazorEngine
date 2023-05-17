#include "ComponentManager.h"

using namespace Razor;

void ComponentManager::EntityDestroyed(Entity entity)
{
	// Remove all of the entities components
	for (const auto& pair : m_componentArrays)
	{
		const auto& componentArray = pair.second;
		if (componentArray->Has(entity))
		{
			componentArray->Remove(entity);
		}
	}
}