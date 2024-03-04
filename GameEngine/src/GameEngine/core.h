#pragma once
//Main import & export Macro

#ifdef GE_PLATFORM_WINDOWS
	#ifdef GE_BUILD_DLL
			#define GAMEENGINE_API __declspec(dllexport)
	#else
			#define GAMEENGINE_API __declspec(dllimport)
	#endif
#else
	#error NOT SUPPORTED!
#endif

#define BIT(x) (1 << x)

