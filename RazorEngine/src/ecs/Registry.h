#ifndef RZ_ECS_REGISTRY_H
#define RZ_ECS_REGISTRY_H

#include "Types.h"

namespace rz {
	class Registry {
	public:
		const EntityID SpawnEntity();
		void DestroyEntity(const EntityID entity);
	};
}

#endif // ! RZ_ECS_REGISTRY_H