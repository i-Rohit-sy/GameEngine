#pragma once
#include "GameEngine/Layer.h"

#include "GameEngine/Events/ApplicationEvent.h"

#include "GameEngine/Events/KeyEvent.h"
#include "GameEngine/Events/MouseEvent.h"

namespace GameEngine {
	class GAMEENGINE_API ImGuiLayer : public Layer
	{
	public:
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}