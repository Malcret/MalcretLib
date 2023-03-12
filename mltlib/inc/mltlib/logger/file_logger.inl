#pragma once

#ifndef MLTLIB_HEADER_ONLY
	#include <mltlib/logger/file_logger.hpp>
#endif // !MLTLIB_HEADER_ONLY

#include <stdio.h>

namespace mltlib {
	namespace logger {
		MLTLIB_INLINE file_logger::file_logger(FILE *output)
			: m_output(output), m_severity_filter(severity_level::LOG_SEVERITY_INFO) {}

		MLTLIB_INLINE void file_logger::set_severity_filter(severity_level severity) {
			m_severity_filter = severity;
		}

		MLTLIB_INLINE void file_logger::log_to_file(const std::string &msg) const {
			fwrite(msg.c_str(), sizeof(char), msg.size(), m_output);
			fflush(m_output);
		}
	}
}