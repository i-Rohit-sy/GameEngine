#pragma once

#include<GameEngine.h>

class ExampleLayer : public GameEngine::Layer
{
public:
	ExampleLayer()
		:Layer("Example")
	{

	}

	void OnUpdate() override
	{
		GE_INFO("ExampleLayer::Update");
	}

	void OnEvent(GameEngine::Event& event) override
	{
		GE_TRACE("{0}", event);
	}
};

class SandBox :public GameEngine::Application
{
public:
	SandBox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new GameEngine::ImGuiLayer());
	}
	~SandBox()
	{

	}
};

GameEngine::Application* GameEngine::CreateApplication()
{
	return new SandBox();
}