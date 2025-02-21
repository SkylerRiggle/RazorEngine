#include "Assert.h"

#ifdef RZ_DEBUG

#include <cstdlib>
#include "Logger.h"

void rz::Assert(const bool condition, const char* err_msg) {
	if (!condition) {
		rz::LogError() << err_msg << std::endl;
		std::abort();
	}
}

#else

void rz::Assert(const bool condition, const char* err_msg) {}

#endif // RZ_DEBUG