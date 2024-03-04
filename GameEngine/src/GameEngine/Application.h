#pragma once

//Contains all the function that can be implemented by the Application.cpp 

#include "core.h"
#include"Events/Event.h"

namespace GameEngine {
	class GAMEENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	//to be defined client
	Application* CreateApplication();

}