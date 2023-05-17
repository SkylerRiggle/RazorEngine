#pragma once

#include "ComponentArray.h"
#include <memory>

namespace Razor
{
	/// <summary>
	/// Manages all component arrays within a scene.
	/// </summary>
	class ComponentManager
	{
	public:
		/// <summary>
		/// Attaches a component to a given entity.
		/// </summary>
		/// <typeparam name="T">The type of component.</typeparam>
		/// <param name="entity">The target entity.</param>
		/// <param name="componentData">The default component data.</param>
		template<typename T>
		void AddComponent(Entity entity, T componentData)
		{
			// Add a component if the array exists
			const char* componentName = ComponentManager::GetComponentName<T>();
			if (this->HasArray<T>(componentName))
			{
				this->GetArray<T>(componentName)->Add(entity, componentData);
				return;
			}

			// Otherwise, create the array, then add the component
			std::shared_ptr<ComponentArray<T>> newArray = std::make_shared<ComponentArray<T>>(new ComponentArray<T>());
			newArray->Add(entity, componentData);
			m_componentArrays.insert({componentName, newArray});
		}

		/// <summary>
		/// Dettaches a component from an entity.
		/// </summary>
		/// <typeparam name="T">The type of component.</typeparam>
		/// <param name="entity">The target entity.</param>
		template<typename T>
		void RemoveComponent(Entity entity)
		{
			const char* componentName = ComponentManager::GetComponentName<T>();
			ASSERT(this->HasArray<T>(componentName));
			this->GetArray<T>(componentName)->Remove(entity);
		}

		/// <summary>
		/// Grabs a component associated with a given entity.
		/// </summary>
		/// <typeparam name="T">The type of component.</typeparam>
		/// <param name="entity">The entity associated with the desired component.</param>
		/// <returns>A component attached to a given entity.</returns>
		template<typename T>
		T& GetComponent(Entity entity)
		{
			const char* componentName = ComponentManager::GetComponentName<T>();
			ASSERT(this->HasArray<T>(componentName));
			return this->GetArray<T>(componentName)->Get(entity);
		}

		/// <summary>
		/// Checks if an entity has a given component.
		/// </summary>
		/// <typeparam name="T">The type of component.</typeparam>
		/// <param name="entity">The entity being queried</param>
		/// <returns>A boolean value indicating if an entity has a component of type T.</returns>
		template<typename T>
		bool HasComponent(Entity entity)
		{
			// Check if an array of type T exists
			const char* componentName = ComponentManager::GetComponentName<T>();
			if (!this->HasArray<T>(componentName))
			{
				return false;
			}

			// Check if the array has the component
			return this->GetArray<T>(componentName)->Has(entity);
		}

		/// <summary>
		/// Handle the destruction of an entity.
		/// </summary>
		/// <param name="entity">The newly destroyed entity.</param>
		void EntityDestroyed(Entity entity);

	private:
		/// <summary>
		/// Get a string name for a given component type.
		/// </summary>
		/// <typeparam name="T">The type of component.</typeparam>
		/// <returns>A string name for a given component type.</returns>
		template<typename T>
		inline static const char* GetComponentName() { return typeid(T).name(); }

		/// <summary>
		/// Checks if an array for a given component type exists.
		/// </summary>
		/// <typeparam name="T">The type of component.</typeparam>
		/// <param name="componentName">The string name of the component.</param>
		/// <returns>A boolean value indicating the arrays existence.</returns>
		template<typename T>
		inline bool HasArray(const char* componentName)
		{
			return m_componentArrays.find(componentName) != m_componentArrays.end();
		}

		/// <summary>
		/// Returns a desired component array.
		/// </summary>
		/// <typeparam name="T">The type of component.</typeparam>
		/// <param name="componentName">The string name of the component.</param>
		/// <returns>A desired component array.</returns>
		template<typename T>
		inline std::shared_ptr<ComponentArray<T>> GetArray(const char* componentName)
		{
			return std::static_pointer_cast<ComponentArray<T>>(m_componentArrays[componentName]);
		}

		std::unordered_map<const char*, std::shared_ptr<IComponentArray>> m_componentArrays{};
	};
}