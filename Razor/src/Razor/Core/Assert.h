#pragma once

#ifdef RZ_DEBUG_BUILD

	#include <intrin.h>
	#include <iostream>

	#define DEBUG_BREAK() __debugbreak()
	constexpr auto RED = "\033[1;31m";
	constexpr auto YELLOW = "\033[1;33m";
	constexpr auto CLEAR = "\033[0m";

	#define ASSERT(expr) \
			if (!(expr)) \
			{ \
				std::cerr << RED << "ERROR [" << __TIME__ << "]: `" << #expr << '`' << std::endl << \
				"Error occured at line " << __LINE__ << " in file " << __FILE__ << std::endl << \
				"Stack Trace:" << CLEAR << std::endl; \
				DEBUG_BREAK(); \
			}
	#define LOG(expr) \
		std::cout << CLEAR << "LOG [" << __TIME__ << "]: " << expr << std::endl;
	#define WARN(expr) \
		std::cout << YELLOW << "WARN [" << __TIME__ << "]: " << expr << CLEAR << std::endl;
#else
	#define ASSERT(expr)
	#define LOG(expr)
	#define WARN(expr)
#endif // RZ_DEBUG_BUILD