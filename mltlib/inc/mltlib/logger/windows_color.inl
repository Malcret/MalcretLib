#pragma once

#ifndef MLTLIB_HEADER_ONLY
	#include <mltlib/logger/windows_color.hpp>
#endif // !MLTLIB_HEADER_ONLY

namespace mltlib::logger {
	MLTLIB_INLINE void set_color(windows_color color) {

	}

	constexpr windows_color severity_to_color(severity_level severity) {
		switch (severity) {
			case severity_level::LOG_SEVERITY_DEBUG:
				return windows_color::WHITE;
			case severity_level::LOG_SEVERITY_TRACE:
				return windows_color::GREY;
			case severity_level::LOG_SEVERITY_INFO:
				return windows_color::GREEN;
			case severity_level::LOG_SEVERITY_WARNING:
				return windows_color::YELLOW;
			case severity_level::LOG_SEVERITY_ERROR:
				return windows_color::LIGHT_RED;
			case severity_level::LOG_SEVERITY_CRITICAL:
				return windows_color::RED;
			default:
				return windows_color::WHITE;
		}
	}
}