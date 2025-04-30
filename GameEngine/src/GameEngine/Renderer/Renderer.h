#pragma once
#include "GameEngine/Renderer/RenderCommand.h"

#include "GameEngine/Renderer/OrthographicCamera.h"
#include "GameEngine/Renderer/Shader.h"
namespace GameEngine {

	class Renderer
	{
	public:
		static void Init();
		static void Shutdown();

		static void OnWindowResize(uint32_t width, uint32_t height);

		static void BeginScene(OrthographicCamera& camera);
		static void EndScene();
		static void Submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

		static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

	private:
		struct SceneData {
			glm::mat4 ViewProjectionMatrix;
		};
		static Scope<SceneData> s_SceneData;
	};


}