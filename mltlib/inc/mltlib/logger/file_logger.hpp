#pragma once

#include <mltlib/common.hpp>
#include <mltlib/logger/severity_level.hpp>
#include <mltlib/string.hpp>

#include <cstdio>
#include <mutex>

namespace mltlib::logger {
	class MLTLIB_API file_logger {
	public:
		MLTLIB_INLINE file_logger(FILE *output = stdout);
		virtual ~file_logger() = default;

		template<typename... Args>
		MLTLIB_INLINE void log(severity_level severity, Args &&...args) {
			if (m_severity_filter <= severity) {
				m_mutex.lock();
				std::string concatenated_string = std::move(concat(args...));
				concatenated_string += "\n";
				this->log_to_file(concatenated_string);
				m_mutex.unlock();
			}
		}

		MLTLIB_INLINE void set_severity_filter(severity_level severity);

	protected:
		FILE *m_output;
		std::mutex m_mutex;
		severity_level m_severity_filter;

		MLTLIB_INLINE void log_to_file(const std::string &message) const;
	};
}

#ifdef MLTLIB_HEADER_ONLY
	#include <mltlib/logger/file_logger.inl>
#endif // MLTLIB_HEADER_ONLY