#pragma once
//log header file with Macro


#include"spdlog/spdlog.h"
#include"core.h"
#include"spdlog/fmt/ostr.h"

namespace GameEngine {

	class GAMEENGINE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}
//core log Macros
#define GE_CORE_INFO(...)	::GameEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GE_CORE_TRACE(...)	::GameEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GE_CORE_WARN(...)	::GameEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GE_CORE_ERROR(...)	::GameEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GE_CORE_FATAL(...)	::GameEngine::Log::GetCoreLogger()->fatel(__VA_ARGS__)

//client log Macros
#define GE_INFO(...)	::GameEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define GE_TRACE(...)	::GameEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GE_WARN(...)	::GameEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GE_ERROR(...)	::GameEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define GE_FATAL(...)	::GameEngine::Log::GetClientLogger()->fatel(__VA_ARGS__)

//function macro
// if dist build
//#define GE_CORE_INFO
