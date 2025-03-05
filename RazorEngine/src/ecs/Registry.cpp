#include "Registry.h"

size_t rz::Registry::s_pool_block_size = 1000 / sizeof(rz::EntityID);

const rz::EntityID rz::Registry::SpawnEntity() {
	if (m_id_pool.IsEmpty()) {
		return m_next_id++;
	}

	rz::EntityID id = m_id_pool.Peek();
	m_id_pool.Pop();
	return id;
}

void rz::Registry::DestroyEntity(const rz::EntityID entity) {
	m_id_pool.Push(entity);
}
