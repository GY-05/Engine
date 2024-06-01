#pragma once
#include"Core.h"
#include<memory>
#include"spdlog/spdlog.h"
#include"spdlog/sinks/stdout_color_sinks.h"
namespace Mar{
	class  MAR_API Log
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

// core log macros
#define MAR_CORE_ERROR(...)		::Mar::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MAR_CORE_INFO(...)		::Mar::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MAR_CORE_ERROR(...)		::Mar::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MAR_CORE_WARN(...)		::Mar::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MAR_CORE_FATAL(...)		::Mar::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//client log macros
#define MAR_ERROR(...)		::Mar::Log::GetClientLogger()->error(__VA_ARGS__)
#define MAR_INFO(...)		::Mar::Log::GetClientLogger()->info(__VA_ARGS__)
#define MAR_ERROR(...)		::Mar::Log::GetClientLogger()->error(__VA_ARGS__)
#define MAR_WARN(...)		::Mar::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MAR_FATAL(...)		::Mar::Log::GetClientLogger()->fatal(__VA_ARGS__)

