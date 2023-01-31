#pragma once

#include <mltlib/common.hpp>
#include <mltlib/logger/severity_level.hpp>

namespace mltlib::logger {
	enum class windows_color {
		BLACK = 0,
		BLUE = 1,
		GREEN = 2,
		AQUA = 3,
		RED = 4,
		PURPLE = 5,
		YELLOW = 6,
		WHITE = 7,
		GREY = 8,
		LIGHT_BLUE = 9,
		LIGHT_GREEN = 10,
		LIGHT_AQUA = 11,
		LIGHT_RED = 12,
		LIGHT_PURPLE = 13,
		LIGHT_YELLOW = 14,
		BRIGHT_WHITE = 15
	};

	void set_color(windows_color color);

	constexpr windows_color severity_to_color(severity_level severity);
}

#ifdef MLTLIB_HEADER_ONLY
#include <mltlib/logger/windows_color.inl>
#endif // MLTLIB_HEADER_ONLY