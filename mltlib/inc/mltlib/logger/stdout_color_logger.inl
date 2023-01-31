#pragma once

#ifndef MLTLIB_HEADER_ONLY
	#include <mltlib/logger/stdout_color_logger.hpp>
#endif // !MLTLIB_HEADER_ONLY

namespace mltlib::logger {
	MLTLIB_INLINE stdout_color_logger::stdout_color_logger()
		: file_logger(stdout) {}

	template<typename... Args>
	MLTLIB_INLINE void stdout_color_logger::log(severity_level severity, Args &&...args) {
		if (m_severity_filter <= severity) {
			m_mutex.lock();
			std::string concatenated_string = std::move(concat(args...));
			concatenated_string += "\n";
			this->log_to_file(concatenated_string);
			m_mutex.unlock();
		}
	}
}