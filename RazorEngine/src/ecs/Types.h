#ifndef RZ_ECS_TYPES_H
#define RZ_ECS_TYPES_H

#include "../core/Types.h"

namespace rz {
	typedef uint32 EntityID;

	class ComponentID {
	public:
		template <typename T>
		static uint32 Get() {
			static uint32 type_id = s_next_id++;
			return type_id;
		}

	private:
		static uint32 s_next_id;
	};

	uint32 ComponentID::s_next_id = 0;
}

#endif // ! RZ_ECS_TYPES_H