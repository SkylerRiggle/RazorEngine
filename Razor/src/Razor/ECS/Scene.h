#pragma once

#include "EntityManager.h"
#include "ComponentManager.h"

namespace Razor
{
	/// <summary>
	/// A scene structure encapsulates a group of entities and their components.
	/// </summary>
	class Scene
	{
	public:
		/// <summary>
		/// Create a new scene object.
		/// </summary>
		Scene();
		~Scene();

		/// <summary>
		/// Create and return a new entity.
		/// </summary>
		/// <returns>A new entity.</returns>
		Entity CreateEntity();

		/// <summary>
		/// Destroys a given entity.
		/// </summary>
		/// <param name="entity">The target entity.</param>
		void DestroyEntity(Entity entity);

		/// <summary>
		/// Attaches a component to a given entity.
		/// </summary>
		/// <typeparam name="T">The type of component.</typeparam>
		/// <param name="entity">The target entity.</param>
		template<typename T>
		inline void AddComponent(Entity entity) 
		{ 
			this->AddComponent<T>(entity, {}); 
		}

		/// <summary>
		/// Attaches a component to a given entity.
		/// </summary>
		/// <typeparam name="T">The type of component.</typeparam>
		/// <param name="entity">The target entity.</param>
		/// <param name="componentData">The default component data.</param>
		template<typename T>
		inline void AddComponent(Entity entity, T componentData)
		{
			m_componentManager->AddComponent(entity, componentData);
		}

		/// <summary>
		/// Dettaches a component from an entity.
		/// </summary>
		/// <typeparam name="T">The type of component.</typeparam>
		/// <param name="entity">The target entity.</param>
		template<typename T>
		inline void RemoveComponent(Entity entity)
		{
			m_componentManager->RemoveComponent<T>(entity);
		}

		/// <summary>
		/// Grabs a component associated with a given entity.
		/// </summary>
		/// <typeparam name="T">The type of component.</typeparam>
		/// <param name="entity">The entity associated with the desired component.</param>
		/// <returns>A component attached to a given entity.</returns>
		template<typename T>
		inline T& GetComponent(Entity entity)
		{
			return m_componentManager->GetComponent<T>(entity);
		}

		/// <summary>
		/// Checks if an entity has a given component.
		/// </summary>
		/// <typeparam name="T">The type of component.</typeparam>
		/// <param name="entity">The entity being queried</param>
		/// <returns>A boolean value indicating if an entity has a component of type T.</returns>
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