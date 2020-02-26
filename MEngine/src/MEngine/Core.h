#pragma once

#ifdef _PLATFORM_WINDOWS
#ifdef _BUILD_DLL
#define MGINE_API __declspec(dllexport)
#else
#define MGINE_API __declspec(dllimport)
#endif // _BUILD_DLL
#else
#ifdef _BUILD_DLL
#define MGINE_API 
#else
#define MGINE_API 
#endif
#endif