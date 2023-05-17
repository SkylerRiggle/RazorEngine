#pragma once

#ifdef RZ_DEBUG_BUILD
	#include <intrin.h>
	#include <iostream>
	#define DEBUG_BREAK() __debugbreak();
	#define ASSERT(expr) \
			if (!(expr)) \
			{ \
				std::cerr << "\033[1;31m" << "ERROR: `" << #expr << '`' << std::endl << \
				"Error occured at line " << __LINE__ << " in file " << __FILE__ << "\033[0m" \
				<< std::endl; \
				DEBUG_BREAK(); \
			}
	#define LOG(expr) std::cout << "LOG: " << expr << std::endl;
	#define WARN(expr) std::cout << "\033[1;33m" << "WARN: " << expr << "\033[0m" << std::endl;
#else
	#define ASSERT(expr)
	#define LOG(expr)
	#define WARN(expr)
#endif // RZ_DEBUG_BUILD