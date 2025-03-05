#ifndef RZ_DSTRUCT_BLOCKLIST_H
#define RZ_DSTRUCT_BLOCKLIST_H

#include "../dbg/Assert.h"

namespace rz {
	template <typename T>
	struct Block {
		Block(const size_t size) : data(new T[size]), next(nullptr), prev(nullptr) {}

		~Block() {
			delete data;
		}

		Block* next;
		Block* prev;

		T* data;
	};

	template <typename T>
	class BlockList {
	public:
		BlockList(const size_t block_size) : m_size(0), m_top_size(0), m_block_size(block_size) {
			m_bottom = new Block<T>(block_size);
			m_top = m_bottom;
		}

		~BlockList() {
			while (m_bottom != nullptr) {
				Block<T>* temp = m_bottom;
				m_bottom = m_bottom->next;
				delete temp;
			}
		}

		void Push(const T& value) {
			m_size++;

			if (m_top_size == m_block_size) {
				m_top->next = new Block<T>(m_block_size);
				m_top->next->prev = m_top;
				m_top = m_top->next;

				m_top_size = 1;
				m_top->data[0] = value;

				return;
			}

			m_top->data[m_top_size] = value;
			m_top_size++;
		}

		void Pop() {
			Assert(m_size > 0, "BlockList is empty!");

			m_size--;

			if (m_top_size == 1 && m_size > 0) {
				m_top = m_top->prev;
				delete m_top->next;
				m_top->next = nullptr;

				m_top_size = m_block_size;

				return;
			}

			m_top_size--;
		}

		T Peek() const {
			Assert(m_size > 0, "BlockList is empty!");
			return m_top->data[m_top_size - 1];
		}

		bool IsEmpty() const {
			return m_size == 0;
		}

		size_t Size() const {
			return m_size;
		}

	private:
		Block<T>* m_bottom;
		Block<T>* m_top;
		size_t m_size, m_top_size;
		size_t m_block_size;
	};
}

#endif // ! RZ_DSTRUCT_BLOCKLIST_H