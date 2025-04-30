#include "ExampleLayer.h"
#include "Sandbox2D.h"
#include <GameEngine.h>
#include <GameEngine/Core/EntryPoint.h>
class Sandbox : public GameEngine::Application
{
public:
	Sandbox()
	{
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{

	}

};

GameEngine::Application* GameEngine::CreateApplication()
{
	return new Sandbox();
}