#pragma once
#include "RenderCommand.h"
#include "OrthoGraphicCamera.h"
#include "Shader.h"

namespace GameEngine {

	class Renderer
	{
	public:
		static void Init();
		static void BeginScene(OrthogpaphicCamera& camera);
		static void EndScene();
		
		static void Submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray,const glm::mat4& transform = glm::mat4(1.0f));

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

	private:
		struct SceneData {
			glm::mat4 ViewProjectionMatrix;
		};
		static SceneData* s_SceneData;
	};


}