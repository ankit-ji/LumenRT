#pragma once

#include <memory>
#include "spdlog/spdlog.h"

namespace LumenRT 
{

	class Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return s_EngineLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetEditorLogger() { return s_EditorLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_EngineLogger;
		static std::shared_ptr<spdlog::logger> s_EditorLogger;
	};
}

#define LOG_ENGINE_TRACE(...)    ::LumenRT::Log::GetEngineLogger()->trace(__VA_ARGS__)
#define LOG_ENGINE_INFO(...)     ::LumenRT::Log::GetEngineLogger()->info(__VA_ARGS__)
#define LOG_ENGINE_WARN(...)     ::LumenRT::Log::GetEngineLogger()->warn(__VA_ARGS__)
#define LOG_ENGINE_ERROR(...)    ::LumenRT::Log::GetEngineLogger()->error(__VA_ARGS__)
#define LOG_ENGINE_CRITICAL(...) ::LumenRT::Log::GetEngineLogger()->critical(__VA_ARGS__)

#define LOG_EDITOR_TRACE(...)    ::LumenRT::Log::GetEditorLogger()->trace(__VA_ARGS__)
#define LOG_EDITOR_INFO(...)     ::LumenRT::Log::GetEditorLogger()->info(__VA_ARGS__)
#define LOG_EDITOR_WARN(...)     ::LumenRT::Log::GetEditorLogger()->warn(__VA_ARGS__)
#define LOG_EDITOR_ERROR(...)    ::LumenRT::Log::GetEditorLogger()->error(__VA_ARGS__)
#define LOG_EDITOR_CRITICAL(...) ::LumenRT::Log::GetEditorLogger()->critical(__VA_ARGS__)
