#pragma once
#include "GameEngine/core/Base.h"

#ifdef GE_PLATFORM_WINDOWS

extern GameEngine::Application* GameEngine::CreateApplication();

int main(int argc, char** argv)
{
	GameEngine::Log::Init();

	GE_PROFILE_BEGIN_SESSION("Startup", "GameEngineProfile-Startup.json");
	auto app = GameEngine::CreateApplication();
	GE_PROFILE_END_SESSION();

	GE_PROFILE_BEGIN_SESSION("Runtime", "GameEngineProfile-Runtime.json");
	app->Run();
	GE_PROFILE_END_SESSION();

	GE_PROFILE_BEGIN_SESSION("Shutdown", "GameEngineProfile-Shutdown.json");
	delete app;
	GE_PROFILE_END_SESSION();
}

#endif