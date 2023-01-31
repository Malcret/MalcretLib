#pragma once

#ifndef MLTLIB_HEADER_ONLY
	#include <mltlib/logger/severity_level.hpp>
#endif // !MLTLIB_HEADER_ONLY

namespace mltlib::logger {
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