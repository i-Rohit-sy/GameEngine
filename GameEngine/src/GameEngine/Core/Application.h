#pragma once

#include "Base.h"

#include "Window.h"
#include "GameEngine/core/LayerStack.h"
#include "GameEngine/Events/Event.h"
#include "GameEngine/Events/ApplicationEvent.h"

#include "GameEngine/Core/Timestep.h"

#include "GameEngine/ImGui/ImGuiLayer.h"


int main(int argc, char** argv);

namespace GameEngine {

	class Application
	{
	public:
		Application(const std::string& name = "GameEngine App");
		virtual ~Application();

		void Close();

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow() { return *m_Window; }

		static Application& Get() { return *s_Instance; }
	private:
		void Run();
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
		
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}