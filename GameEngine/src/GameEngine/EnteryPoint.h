#pragma once

#ifdef GE_PLATFORM_WINDOWS

extern GameEngine::Application* GameEngine::CreateApplication();
int main(int argc,char**argv)
{
	GameEngine:: Log ::Init();
	GE_CORE_WARN("INITALIZING LOG!!!");
	GE_CORE_INFO("HELLO");

	auto app = GameEngine::CreateApplication();
	app->Run();
	delete app;
}

#endif
