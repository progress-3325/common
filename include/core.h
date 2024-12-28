#pragma once

#ifdef CM_PLATFORM_WINDOWS
	#ifdef CM_BUILD_DLL
		#define COMMON_API _declspec(dllexport)
#else
		#define COMMON_API _declspec(dllimport)
#endif

#endif

