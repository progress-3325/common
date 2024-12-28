#include "log.h"

namespace corecommon {
	std::shared_ptr<spdlog::logger> log::s_coreLogger;
	std::shared_ptr<spdlog::logger> log::s_clientLogger;

	void log::Init() {
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_coreLogger = spdlog::stdout_color_mt("ENGINE");
		s_coreLogger->set_level(spdlog::level::trace);
		s_clientLogger = spdlog::stdout_color_mt("LOCAL");
		s_clientLogger->set_level(spdlog::level::trace);
	}
}