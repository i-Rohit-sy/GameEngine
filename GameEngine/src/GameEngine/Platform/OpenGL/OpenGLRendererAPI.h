#pragma once
#include"GameEngine/Renderer/RendererAPI.h"


namespace GameEngine {
	class OpenGLRendererAPI : public RendererAPI
	{
	public:
		virtual void setClearColor(const glm::vec4& color) override;
		virtual void Clear() override;

		virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) override;
	};

}
