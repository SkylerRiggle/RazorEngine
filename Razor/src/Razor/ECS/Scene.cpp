#include "Scene.h"

using namespace Razor;

Scene::Scene()
{
	m_entityManager = new EntityManager();
	m_componentManager = new ComponentManager();
}

Scene::~Scene()
{
	delete m_entityManager;
	delete m_componentManager;
}

Entity Scene::CreateEntity()
{
	return m_entityManager->CreateEntity();
}

void Scene::DestroyEntity(Entity entity)
{
	m_entityManager->DestroyEntity(entity);
}