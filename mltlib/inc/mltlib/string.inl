#pragma once

#ifndef MLTLIB_HEADER_ONLY
#	include <mltlib/string.hpp>
#endif // !MLTLIB_HEADER_ONLY

namespace mltlib {
	MLTLIB_INLINE std::wstring string_to_wstring(const std::string &str) {
		std::wstring wstr;
		size_t size;
		wstr.resize(str.length());
		mbstowcs_s(&size, &wstr[0], wstr.size() + 1, str.c_str(), str.size());
		return wstr;
	}

	MLTLIB_INLINE std::string wstring_to_string(const std::wstring &wstr) {
		std::string str;
		size_t size;
		str.resize(wstr.length());
		wcstombs_s(&size, &str[0], str.size() + 1, wstr.c_str(), wstr.size());
		return str;
	}
}