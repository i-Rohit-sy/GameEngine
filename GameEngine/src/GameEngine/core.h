#pragma once

#ifdef GE_PLATFORM_WINDOWS
	#ifdef GE_BUILD_DLL
			#define GAMEENGINE_API__declspec(dllexport)
	#else
			#define GAMEENGINE_API__declspec(dllimport)
	#endif
#else
	#error NOT SUPPORTED!
#endif

