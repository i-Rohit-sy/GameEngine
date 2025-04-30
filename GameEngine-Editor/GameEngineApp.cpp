#include <GameEngine.h>
#include <GameEngine/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace GameEngine {

	class GameEngineEditor : public Application
	{
	public:
		GameEngineEditor()
			: Application("GameEngine Editor")
		{
			PushLayer(new EditorLayer());
		}

		~GameEngineEditor()
		{
		}
	};

	Application* CreateApplication()
	{
		return new GameEngineEditor();
	}

}