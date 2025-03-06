#ifndef RZ_DSTRUCT_TUPLE_H
#define RZ_DSTRUCT_TUPLE_H

#include <stdexcept>
#include <type_traits>

namespace rz {
	template <typename... Tn>
	struct Tuple;

	template <>
	struct Tuple<> {
	public:
		Tuple() = default;

		template <typename T>
		T& Get() {
			static_assert(false, "Type not found in tuple!");
			throw std::runtime_error("Type not found in tuple!");
		}
	};
	
	template <typename T1, typename... Tn>
	struct Tuple<T1, Tn...> : Tuple<Tn...> {
	public:
		Tuple(T1 v1, Tn... vn) : m_value(v1), Tuple<Tn...>(vn...) {}

		template <typename T>
		T& Get() {
			return Tuple<Tn...>::template Get<T>();
		}

		template <>
		T1& Get<T1>() {
			return m_value;
		}

	private:
		T1 m_value;
	};
}

#endif // ! RZ_DSTRUCT_TUPLE_H