#pragma once

#ifdef MN_PLATFORM_WINDOWS
	#ifdef MN_BUILD_DLL
		#define MIN_API __declspec(dllexport)
	#else
		#define MIN_API __declspec(dllimport)
	#endif
#else
	#error Min only support Windows!
#endif

#define BIT(x) (1 << x)