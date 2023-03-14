#pragma once

#ifndef MLTLIB_HEADER_ONLY
#	include <mltlib/time.hpp>
#endif // !MLTLIB_HEADER_ONLY

#include <iostream>
#include <ctime>

namespace mltlib {
	MLTLIB_INLINE std::string format_time(const std::string &format) {
		time_t t;
		tm time_local;
		size_t buffer_size = 32;
		std::string buffer(buffer_size, '\0');
		
		time(&t);
		localtime_s(&time_local, &t);
		while (!strftime(buffer.data(), buffer_size, format.c_str(), &time_local)) {
			buffer_size *= 2;
			buffer.resize(buffer_size, '\0');
		}

		return buffer;
	}
}