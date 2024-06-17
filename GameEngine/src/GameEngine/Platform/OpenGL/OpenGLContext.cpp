#include "hzpch.h"
#include "OpenGLContext.h"
#include <GLFW/glfw3.h>
#include "glad/glad.h"
#include "GameEngine/Log.h"
#include <GL/GL.h>

namespace GameEngine {
	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		:m_WindowHandle(windowHandle)
	{
		GE_CORE_ASSERT(windowHandle, "Windows Handle is Null");
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		GE_CORE_ASSERT(status, "Failed to initialize Glad!");
		//Graphics VEndor Information
		GE_CORE_INFO("  OpenGL Info:");
		GE_CORE_INFO("  OpenGL {0}.{0}", GLVersion.major, GLVersion.minor);
		/*GE_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		GE_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		GE_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));*/
	}
	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);

	}

}