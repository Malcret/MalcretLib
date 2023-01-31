#pragma once

#ifndef MLTLIB_HEADER_ONLY
	#include <mltlib/logger/file_logger.hpp>
#endif // !MLTLIB_HEADER_ONLY

#include <stdio.h>
#include <mltlib/string.hpp>

namespace mltlib {
	namespace logger {
		MLTLIB_INLINE file_logger::file_logger(FILE *output)
			: m_output(output), m_severity_filter(severity_level::LOG_SEVERITY_INFO) {}

		template<typename... Args>
		MLTLIB_INLINE void file_logger::log(severity_level severity, Args &&...args) {
			if (m_severity_filter <= severity) {
				m_mutex.lock();
				std::string concatenated_string = std::move(concat(args...));
				concatenated_string += "\n";
				this->log_to_file(concatenated_string);
				m_mutex.unlock();
			}
		}

		MLTLIB_INLINE void file_logger::set_severity_filter(severity_level severity) {
			m_severity_filter = severity;
		}

		MLTLIB_INLINE void file_logger::log_to_file(const std::string &msg) {
			::fwrite(msg.c_str(), sizeof(char), msg.size(), m_output);
			::fflush(m_output);
		}
	}
}