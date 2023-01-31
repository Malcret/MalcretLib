#pragma once

#include <mltlib/common.hpp>
#include <mltlib/logger/severity_level.hpp>

#include <cstdio>
#include <mutex>

namespace mltlib::logger {
	class MLTLIB_API file_logger {
	public:
		file_logger(FILE *output = stdout);
		virtual ~file_logger() = default;

		template<typename... Args>
		void log(severity_level severity, Args &&...args);

		void set_severity_filter(severity_level severity);

	protected:
		FILE *m_output;
		std::mutex m_mutex;
		severity_level m_severity_filter;

		void log_to_file(const std::string &message);
	};
}

#ifdef MLTLIB_HEADER_ONLY
	#include <mltlib/logger/file_logger.inl>
#endif // MLTLIB_HEADER_ONLY