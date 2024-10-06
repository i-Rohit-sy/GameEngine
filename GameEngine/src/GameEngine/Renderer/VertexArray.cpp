#include "hzpch.h"
#include "VertexArray.h"
#include "GameEngine/Log.h"
#include "Renderer.h"
#include "GameEngine/Platform/OpenGL/OpenGLVertexArray.h"

namespace GameEngine {

	VertexArray* VertexArray::Create()
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    GE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return new OpenGLVertexArray();
		}

		GE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}