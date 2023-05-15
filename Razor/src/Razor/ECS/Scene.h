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
		inline void AddComponent(Entity entity) 
		{ 
			this->AddComponent<T>(entity, {}); 
		}

		template<typename T>
		inline void AddComponent(Entity entity, T componentData)
		{
			m_componentManager->AddComponent(entity, componentData);
		}

		template<typename T>
		inline void RemoveComponent(Entity entity)
		{
			m_componentManager->RemoveComponent<T>(entity);
		}

		template<typename T>
		inline T& GetComponent(Entity entity)
		{
			return m_componentManager->GetComponent<T>(entity);
		}

		template<typename T>
		inline bool HasComponent(Entity entity)
		{
			return m_componentManager->HasComponent<T>(entity);
		}

	private:
		EntityManager* m_entityManager;
		ComponentManager* m_componentManager;
	};
}