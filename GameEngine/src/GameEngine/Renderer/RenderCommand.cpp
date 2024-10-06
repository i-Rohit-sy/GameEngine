#include"hzpch.h"
#include"RenderCommand.h"
#include "GameEngine/Platform/OpenGL/OpenGLRendererAPI.h"

namespace GameEngine {
	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;
}