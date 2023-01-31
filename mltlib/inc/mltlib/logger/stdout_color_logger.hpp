#pragma once

#include <mltlib/common.hpp>
#include <mltlib/logger/file_logger.hpp>

namespace mltlib::logger {
	class stdout_color_logger : file_logger {
	public:
		stdout_color_logger();
		~stdout_color_logger() = default;

		template<typename... Args>
		void log(severity_level severity, Args &&...args);

	private:
	};
}

#ifdef MLTLIB_HEADER_ONLY
	#include <mltlib/logger/stdout_color_logger.hpp>
#endif // MLTLIB_HEADER_ONLY