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

	constexpr std::string severity_level_to_str(severity_level sev);
}

#ifdef MLTLIB_HEADER_ONLY
	#include <mltlib/logger/severity_level.inl>
#endif // MLTLIB_HEADER_ONLY