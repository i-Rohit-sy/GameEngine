#pragma once

//Contains all the function that can be implemented by the Application.cpp 
#include "core.h"
#include "Window.h"
#include "GameEngine/LayerStack.h"
#include "GameEngine/Events/Event.h"
#include "GameEngine/Events/ApplicationEvent.h"
#include "GameEngine/Core/Timestep.h"
#include "GameEngine/ImGui/ImGuiLayer.h"


namespace GameEngine {
	class Application
	{
	public:
		Application();
		virtual ~Application() = default;
		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application*s_Instance;

	};
	//to be defined client
	Application* CreateApplication();

}