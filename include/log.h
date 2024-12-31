#pragma once
#pragma warning(disable: 4251)

#include <core.h>
#include "spdlog/spdlog.h"
#include <memory>
#include "spdlog/sinks/stdout_color_sinks.h"
#include "application.h"

namespace corecommon {
	class COMMON_API log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_clientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_coreLogger;
		static std::shared_ptr<spdlog::logger> s_clientLogger;
	};
}


// core log macros
#define CM_CORE_TRACE(...)			::corecommon::log::getCoreLogger()->trace(__VA_ARGS__)
#define CM_CORE_INFO(...)			::corecommon::log::getCoreLogger()->info(__VA_ARGS__)
#define CM_CORE_WARN(...)			::corecommon::log::getCoreLogger()->warn(__VA_ARGS__)
#define CM_CORE_ERROR(...)			::corecommon::log::getCoreLogger()->error(__VA_ARGS__)
#define CM_CORE_CRITICAL(...)		::corecommon::log::getCoreLogger()->critical(__VA_ARGS__)

// client log macros
#define CM_TRACE(...)				::corecommon::log::getClientLogger()->trace(__VA_ARGS__)
#define CM_INFO(...)				::corecommon::log::getClientLogger()->info(__VA_ARGS__)
#define CM_WARN(...)				::corecommon::log::getClientLogger()->warn(__VA_ARGS__)
#define CM_ERROR(...)				::corecommon::log::getClientLogger()->error(__VA_ARGS__)
#define CM_CRITICAL(...)			::corecommon::log::getClientLogger()->critical(__VA_ARGS__)
