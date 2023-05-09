#pragma once

#include "EntityManager.h"
#include "ComponentManager.h"

namespace Razor
{
	class Scene
	{
	public:
		Scene();
		~Scene();

		Entity CreateEntity();
		void DestroyEntity(Entity entity);

		template<typename T>
		void RegisterComponentType()
		{
			m_componentManager->RegisterComponentType<T>();
		}

		template<typename T>
		void AddComponent(Entity entity, T componentData)
		{
			m_componentManager->AddComponent(entity, componentData);
		}

		template<typename T>
		void RemoveComponent(Entity entity)
		{
			m_componentManager->RemoveComponent<T>(entity);
		}

		template<typename T>
		T& GetComponent(Entity entity)
		{
			return m_componentManager->GetComponent<T>(entity);
		}

	private:
		EntityManager* m_entityManager;
		ComponentManager* m_componentManager;
	};
}