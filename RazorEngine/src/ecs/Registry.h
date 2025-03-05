#ifndef RZ_ECS_REGISTRY_H
#define RZ_ECS_REGISTRY_H

#include "Types.h"
#include "../dstruct/BlockList.h"

namespace rz {
	class Registry {
	public:
		const EntityID SpawnEntity();
		void DestroyEntity(const EntityID entity);

	private:
		static size_t s_pool_block_size;

		EntityID m_next_id = 0;
		BlockList<EntityID> m_id_pool{ s_entity_pool_block_size };
	};
}

#endif // ! RZ_ECS_REGISTRY_H