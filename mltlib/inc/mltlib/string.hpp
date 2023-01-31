#pragma once

#include <mltlib/common.hpp>

#include <string>

namespace mltlib {
	constexpr std::string to_string(const std::string &str);
	
	template<typename... Args>
	constexpr std::string concat(Args &&...args);
}

#ifdef MLTLIB_HEADER_ONLY
	#include <mltlib/string.inl>
#endif // MLTLIB_HEADER_ONLY