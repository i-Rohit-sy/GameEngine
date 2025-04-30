#pragma once
#include"GameEngine/core/Base.h"
#include"GameEngine/Events/Event.h"
#include "GameEngine/Core/Timestep.h"

namespace GameEngine {
	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer()=default;


		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {} 
		virtual void OnUpdate(Timestep ts) {}

		const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;

	};
}
