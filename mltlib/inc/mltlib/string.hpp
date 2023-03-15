#pragma once

#include <mltlib/common.hpp>

#include <string>

namespace mltlib {
	constexpr std::string to_string(const std::string &str) { return str; }
	MLTLIB_INLINE std::wstring string_to_wstring(const std::string &str);
	MLTLIB_INLINE std::string wstring_to_string(const std::wstring &wstr);
	
	template<typename... Args>
	constexpr std::string concat(Args &&...args) {
		std::string concatenated_string;
		using std::to_string;
		using mltlib::to_string;
		int unpack[]{ (concatenated_string += to_string(args), 0)... };
		(void)unpack;
		return concatenated_string;
	}
}

#ifdef MLTLIB_HEADER_ONLY
#	include <mltlib/string.inl>
#endif // MLTLIB_HEADER_ONLY