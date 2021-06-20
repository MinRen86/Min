#pragma once

#include <Min/Core.h>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace Min
{
	class MIN_API Log
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

#define MN_CORE_TRACE(...)	::Min::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define MN_CORE_INFO(...)	::Min::Log::GetCoreLogger()->info(__VA_ARGS__)
#define MN_CORE_WARN(...)	::Min::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define MN_CORE_ERROR(...)	::Min::Log::GetCoreLogger()->error(__VA_ARGS__)
#define MN_CORE_FATAL(...)	::Min::Log::GetCoreLogger()->fatal(__VA_ARGS__)


#define MN_TRACE(...)		::Min::Log::GetClientLogger()->trace(__VA_ARGS__)
#define MN_INFO(...)		::Min::Log::GetClientLogger()->info(__VA_ARGS__)
#define MN_WARN(...)		::Min::Log::GetClientLogger()->warn(__VA_ARGS__)
#define MN_ERROR(...)		::Min::Log::GetClientLogger()->error(__VA_ARGS__)
#define MN_FATAL(...)		::Min::Log::GetClientLogger()->fatal(__VA_ARGS__)

