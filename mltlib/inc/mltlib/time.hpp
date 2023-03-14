#pragma once

#include <mltlib/common.hpp>

#include <string>

namespace mltlib {
	MLTLIB_INLINE std::string format_time(const std::string &format);
}

#ifdef MLTLIB_HEADER_ONLY
#	include <mltlib/time.inl>
#endif // MLTLIB_HEADER_ONLY