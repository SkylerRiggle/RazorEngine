#pragma once

#include "../Types.h"
#include "../Assert.h"
#include <array>
#include <unordered_map>

namespace Razor
{
	/// <summary>
	/// The base abstract component array.
	/// GUARANTEES CERTAIN INTERACTIONS.
	/// </summary>
	class IComponentArray
	{
	public:
		virtual void Remove(Entity entity) = 0;
		virtual inline bool Has(Entity entity) = 0;
	};

	/// <summary>
	/// A data structure for managing entity component data.
	/// </summary>
	/// <typeparam name="T">The type of component stored by this array.</typeparam>
	template<typename T>
	class ComponentArray : public IComponentArray
	{
	public:
		/// <summary>
		/// Attaches a component to a given entity.
		/// </summary>
		/// <param name="entity">The target entity.</param>
		/// <param name="componentData">The default component data.</param>
		void Add(Entity entity, T componentData)
		{
			// Return if the entity already has this component
			if (this->Has(entity))
			{
				return;
			}

			// Otherwise, add the component
			m_components[m_size] = componentData;
			m_entityToIndex.insert({ entity, m_size });
			m_indexToEntity.insert({ m_size, entity });
			m_size++;
		}

		/// <summary>
		/// Dettaches a component from an entity.
		/// </summary>
		/// <param name="entity">The target entity.</param>
		void Remove(Entity entity) override
		{
			// Ensure the entity has the component
			ASSERT(this->Has(entity));

			// Compute indicies
			size_t removeIndex = m_entityToIndex[entity];
			m_size--;

			// Erase the old data
			m_components[removeIndex] = m_components[m_size];
			m_entityToIndex.erase(entity);
			m_indexToEntity.erase(m_size);

			// Reevaluate index and entity maps
			Entity lastEntity = m_indexToEntity[m_size];
			m_entityToIndex[lastEntity] = removeIndex;
			m_indexToEntity[removeIndex] = lastEntity;
		}

		/// <summary>
		/// Checks if an entity has a given component.
		/// </summary>
		/// <param name="entity">The entity being queried</param>
		/// <returns>A boolean value indicating if an entity has a component.</returns>
		inline bool Has(Entity entity) override { return m_entityToIndex.find(entity) != m_entityToIndex.end(); }

		/// <summary>
		/// Grabs a component associated with a given entity.
		/// </summary>
		/// <param name="entity">The entity associated with the desired component.</param>
		/// <returns>A component attached to a given entity.</returns>
		T& Get(Entity entity)
		{
			ASSERT(this->Has(entity));
			return m_components[m_entityToIndex[entity]];
		}

	private:
		std::array<T, MAX_ENTITIES> m_components{};
		std::unordered_map<Entity, size_t> m_entityToIndex{};
		std::unordered_map<size_t, Entity> m_indexToEntity{};
		size_t m_size = 0;
	};
}