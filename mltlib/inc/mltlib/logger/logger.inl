#pragma once

#ifndef MLTLIB_HEADER_ONLY
#	include <mltlib/logger/logger.hpp>
#endif // !MLTLIB_HEADER_ONLY

namespace mltlib::logger {
	MLTLIB_INLINE logger::logger(const std::string &name)
		: m_name(name), m_severity_filter(severity_level::LOG_SEVERITY_INFO) {}

	MLTLIB_INLINE void logger::set_severity_filter(severity_level severity) {
		m_severity_filter = severity;
	}
}