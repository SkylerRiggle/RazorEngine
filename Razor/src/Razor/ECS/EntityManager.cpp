#include "EntityManager.h"

using namespace Razor;

EntityManager::EntityManager()
{
	// Fill the entity pool
	for (Entity newEntity = 0; newEntity < MAX_ENTITIES; newEntity++)
	{
		m_entityPool.push(newEntity);
	}

	// Default entity count
	m_entityCount = 0;
}

Entity EntityManager::CreateEntity()
{
	// Ensure that the entity ceiling hasn't been reached
	ASSERT(m_entityCount < MAX_ENTITIES);

	// Otherwise, return an entity from the pool
	Entity newEntity = m_entityPool.front();
	m_entityPool.pop();
	m_entityCount++;
	return newEntity;
}

void EntityManager::DestroyEntity(Entity entity)
{
	// Ensure that the entity is in the legal bounds
	ASSERT(entity < MAX_ENTITIES);

	// Otherwise, return the entity to the pool
	m_entityPool.push(entity);
	m_entityCount--;
}