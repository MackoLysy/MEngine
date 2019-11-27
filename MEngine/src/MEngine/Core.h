#pragma once

#ifdef _PLATFORM_WINDOWS
#ifdef _BUILD_DLL
#define MGINE_API __declspec(dllexport)
#else
#define MGINE_API __declspec(dllimport)
#endif // _BUILD_DLL
#else
	#error ONLY WINDOWS FOR NOW :(
#endif