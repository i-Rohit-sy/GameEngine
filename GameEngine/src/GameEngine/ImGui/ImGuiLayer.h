#pragma once
#include "GameEngine/core/Layer.h"

#include "GameEngine/Events/ApplicationEvent.h"

#include "GameEngine/Events/KeyEvent.h"
#include "GameEngine/Events/MouseEvent.h"

namespace GameEngine {
	class ImGuiLayer : public Layer
	{
	public:
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;

		virtual void OnEvent(Event& e) override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}