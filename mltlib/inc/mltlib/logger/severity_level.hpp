#pragma once

#include <mltlib/common.hpp>

#include <string>

namespace mltlib::logger {
	enum class severity_level {
		LOG_SEVERITY_TRACE    = 0,
		LOG_SEVERITY_DEBUG    = 1,
		LOG_SEVERITY_INFO     = 2,
		LOG_SEVERITY_WARNING  = 3,
		LOG_SEVERITY_ERROR    = 4,
		LOG_SEVERITY_CRITICAL = 5
	};

	constexpr std::string severity_level_to_str(severity_level severity) {
		switch (severity) {
			case severity_level::LOG_SEVERITY_TRACE:
				return "TRACE";
			case severity_level::LOG_SEVERITY_DEBUG:
				return "DEBUG";
			case severity_level::LOG_SEVERITY_INFO:
				return "INFO";
			case severity_level::LOG_SEVERITY_WARNING:
				return "WARNING";
			case severity_level::LOG_SEVERITY_ERROR:
				return "ERROR";
			case severity_level::LOG_SEVERITY_CRITICAL:
				return "CRITICAL";
			default:
				return "UNKNOW";
		}
	}
}