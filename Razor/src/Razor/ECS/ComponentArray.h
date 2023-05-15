#pragma once

#include "../Types.h"
#include "../Assert.h"
#include <array>
#include <unordered_map>

namespace Razor
{
	class IComponentArray
	{
	public:
		virtual void Remove(Entity entity) = 0;
		virtual inline bool Has(Entity entity) = 0;
	};

	template<typename T>
	class ComponentArray : public IComponentArray
	{
	public:
		void Add(Entity entity, T componentData)
		{
			if (this->Has(entity))
			{
				return;
			}

			m_components[m_size] = componentData;
			m_entityToIndex.insert({ entity, m_size });
			m_indexToEntity.insert({ m_size, entity });
			m_size++;
		}

		void Remove(Entity entity) override
		{
			ASSERT(this->Has(entity));

			size_t removeIndex = m_entityToIndex[entity];
			m_size--;

			m_components[removeIndex] = m_components[m_size];
			m_entityToIndex.erase(entity);
			m_indexToEntity.erase(m_size);

			Entity lastEntity = m_indexToEntity[m_size];
			m_entityToIndex[lastEntity] = removeIndex;
			m_indexToEntity[removeIndex] = lastEntity;
		}

		inline bool Has(Entity entity) override { return m_entityToIndex.find(entity) != m_entityToIndex.end(); }

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