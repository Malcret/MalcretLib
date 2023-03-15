#pragma once

#include <mltlib/common.hpp>
#include <mltlib/logger/severity_level.hpp>
#include <mltlib/string.hpp>
#include <mltlib/time.hpp>

#include <mutex>

namespace mltlib::logger {
	class MLTLIB_API logger {
	public:
		MLTLIB_INLINE logger(const std::string &name);
		MLTLIB_INLINE virtual ~logger() = default;

		template<typename... Args>
		MLTLIB_INLINE void log(severity_level severity, Args &&...args) {
			if (m_severity_filter <= severity) {
				std::string concatenated_string = concat(format_time("[%T] "), m_name, ", ", severity_level_to_str(severity), ": ", args...);
				concatenated_string += "\n";
				m_mutex.lock();
				_log(concatenated_string);
				m_mutex.unlock();
			}
		}

		MLTLIB_INLINE void set_severity_filter(severity_level severity);

	protected:
		const std::string m_name;
		severity_level m_severity_filter;
		std::mutex m_mutex;

		MLTLIB_INLINE virtual void _log(const std::string &msg) const = 0;
	};
}

#ifdef MLTLIB_HEADER_ONLY
#	include <mltlib/logger/logger.inl>
#endif // MLTLIB_HEADER_ONLY