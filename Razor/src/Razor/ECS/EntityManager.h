#pragma once

#include "../Core/Types.h"
#include "../Core/Assert.h"
#include <queue>

namespace Razor
{
	/// <summary>
	/// The entity manager is responsible for the creation and
	/// deletion of entities. It also enforces the engines maximum
	/// entity count.
	/// </summary>
	class EntityManager
	{
	public:
		/// <summary>
		/// Create a new entity manager.
		/// </summary>
		EntityManager();

		/// <summary>
		/// Create and return a new entity id.
		/// </summary>
		/// <returns>A new entity.</returns>
		Entity CreateEntity();

		/// <summary>
		/// Destroy an entity id.
		/// </summary>
		/// <param name="entity">The entity to be destroyed.</param>
		void DestroyEntity(Entity entity);

		/// <summary>
		/// Get the current entity count.
		/// </summary>
		/// <returns>The current number of active entities.</returns>
		inline size_t GetEntityCount() { return m_entityCount; }

	private:
		std::queue<Entity> m_entityPool{};
		size_t m_entityCount;
	};
}

