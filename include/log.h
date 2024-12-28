#pragma once
#pragma warning(disable: 4251)

#include <core.h>
#include "spdlog/spdlog.h"
#include <memory>
#include "spdlog/sinks/stdout_color_sinks.h"

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


