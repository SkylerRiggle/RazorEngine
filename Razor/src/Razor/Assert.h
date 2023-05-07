#pragma once

#ifdef RZ_DEBUG_BUILD
	#include <intrin.h>
	#include <iostream>
	#define DEBUG_BREAK() __debugbreak();
	#define ASSERT(expr) \
			if (!(expr)) \
			{ \
				std::cerr << "Assertion Failed: `" << #expr << '`' << std::endl << \
				"Error occured at line " << __LINE__ << " in file " << __FILE__ << std::endl; \
				DEBUG_BREAK(); \
			}
#else
	#define ASSERT(expr)
#endif // RZ_DEBUG_BUILD