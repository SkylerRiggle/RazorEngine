#include "Scene.h"

using namespace Razor;

Scene::Scene()
{
	// Create the scene sub-managers
	m_entityManager = new EntityManager();
	m_componentManager = new ComponentManager();
}

Scene::~Scene()
{
	// Delete the scene sub-managers
	delete m_entityManager;
	delete m_componentManager;
}

Entity Scene::CreateEntity()
{
	return m_entityManager->CreateEntity();
}

void Scene::DestroyEntity(Entity entity)
{
	// Synchronize the destroyed entity across all sub-systems
	m_entityManager->DestroyEntity(entity);
	m_componentManager->EntityDestroyed(entity);
}