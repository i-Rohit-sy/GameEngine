#pragma once

#include "core.h"

namespace GameEngine {
	class __declspec(dllexport) Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	//to be defined client
	Application* CreateApplication();

}