#pragma once

#ifdef RZ_DEBUG_BUILD

	#include <intrin.h>
	#include <iostream>

	#define DEBUG_BREAK() __debugbreak()
	#define TIME_STAMP() "99:99:99"
	#define STACK_TRACE() "STACK TRACE"

	constexpr auto RED = "\033[1;31m";
	constexpr auto YELLOW = "\033[1;33m";
	constexpr auto CLEAR = "\033[0m";

	#define ASSERT(expr) \
			if (!(expr)) \
			{ \
				std::cerr << RED << TIME_STAMP() << " [ERROR]: " << #expr << std::endl << \
				"Error occured at line " << __LINE__ << " in file " << __FILE__ << std::endl << \
				"Stack Trace:" << std::endl << STACK_TRACE() << CLEAR << std::endl; \
				DEBUG_BREAK(); \
			}
	#define LOG(expr) \
		std::cout << CLEAR << TIME_STAMP() << " [LOG]: " << expr << std::endl;
	#define WARN(expr) \
		std::cout << YELLOW << TIME_STAMP() << " [WARN]: " << expr << CLEAR << std::endl;
#else
	#define ASSERT(expr)
	#define LOG(expr)
	#define WARN(expr)
#endif // RZ_DEBUG_BUILD