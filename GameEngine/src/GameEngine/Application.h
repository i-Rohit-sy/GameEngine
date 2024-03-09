#pragma once

//Contains all the function that can be implemented by the Application.cpp 

#include "core.h"
#include"Events/Event.h"
#include "Window.h"

namespace GameEngine {
	class GAMEENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};
	//to be defined client
	Application* CreateApplication();

}