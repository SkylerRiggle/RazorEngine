#pragma once

#ifdef RZ_PLATFORM_WINDOWS
	#ifdef RZ_BUILD_DLL
		#define RAZOR_API __declspec(dllexport)
	#else
		#define RAZOR_API __declspec(dllimport)
	#endif // RZ_BUILD_DLL
#else
	#error CURRENTLY ONLY SUPPORTS WINDOWS!
#endif // RZ_PLATFORM_WINDOW


#ifdef RZ_DEBUG_BUILD
#else
#endif // RZ_DEBUG_BUILD
