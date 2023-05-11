#pragma once

#include "ComponentArray.h"
#include <memory>

namespace Razor
{
	class ComponentManager
	{
	public:
		template<typename T>
		void AddComponent(Entity entity, T componentData)
		{
			const char* componentName = ComponentManager::GetComponentName<T>();
			if (this->HasArray<T>(componentName))
			{
				this->GetArray<T>(componentName)->Add(entity, componentData);
				return;
			}

			std::shared_ptr<ComponentArray<T>> newArray = std::make_shared<ComponentArray<T>>(new ComponentArray<T>());
			newArray->Add(entity, componentData);
			m_componentArrays.insert({componentName, newArray});
		}

		template<typename T>
		void RemoveComponent(Entity entity)
		{
			const char* componentName = ComponentManager::GetComponentName<T>();
			ASSERT(this->HasArray<T>(componentName));
			this->GetArray<T>(componentName)->Remove(entity);
		}

		template<typename T>
		T& GetComponent(Entity entity)
		{
			const char* componentName = ComponentManager::GetComponentName<T>();
			ASSERT(this->HasArray<T>(componentName));
			return this->GetArray<T>(componentName)->Get(entity);
		}

		template<typename T>
		bool HasComponent(Entity entity)
		{
			const char* componentName = ComponentManager::GetComponentName<T>();
			if (!this->HasArray<T>(componentName))
			{
				return false;
			}

			return this->GetArray<T>(componentName)->Has(entity);
		}

		void EntityDestroyed(Entity entity);

	private:
		template<typename T>
		inline static const char* GetComponentName() { return typeid(T).name(); }

		template<typename T>
		inline bool HasArray(const char* componentName)
		{
			return m_componentArrays.find(componentName) != m_componentArrays.end();
		}

		template<typename T>
		inline std::shared_ptr<ComponentArray<T>> GetArray(const char* componentName)
		{
			return std::static_pointer_cast<ComponentArray<T>>(m_componentArrays[componentName]);
		}

		std::unordered_map<const char*, std::shared_ptr<IComponentArray>> m_componentArrays{};
	};
}