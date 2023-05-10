#pragma once

#include "ComponentArray.h"

namespace Razor
{
	class ComponentManager
	{
	public:
		template<typename T>
		void AddComponent(Entity entity, T componentData)
		{
			ComponentArray<T>* componentArray = GetComponentArray<T>();

		}

		template<typename T>
		void RemoveComponent(Entity entity)
		{

		}

		template<typename T>
		T& GetComponent(Entity entity)
		{

		}

		template<typename T>
		bool HasComponent(Entity entity)
		{
			const char* componentName = typeid(T).name();
			if (m_typeToArray.find(componentName) == m_typeToArray.end())
			{
				return false;
			}

			ComponentArray<T>* componentArray = (ComponentArray<T>*)m_typeToArray[componentName];
			return componentArray->entityToIndex.find(entity) != componentArray->entityToIndex.end();
		}

		void EntityDestroyed(Entity entity);

	private:
		template<typename T>
		ComponentArray<T>* GetComponentArray()
		{
			const char* componentName = typeid(T).name();
			if (m_typeToArray.find(componentName) != m_typeToArray.end())
			{
				return (ComponentArray<T>*)m_typeToArray[componentName];
			}

			ComponentArray<T>* newArray = new ComponentArray<T>();
			m_typeToArray.insert(componentName, newArray);
			return newArray;
		}

		std::unordered_map<const char*, IComponentArray*> m_typeToArray{};
	};
}