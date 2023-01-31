#pragma once

#ifndef MLTLIB_HEADER_ONLY
	#include <mltlib/string.hpp>
#endif // !MLTLIB_HEADER_ONLY

namespace mltlib {
	constexpr std::string to_string(const std::string &str) {
		return str;
	}

	template<typename... Args>
	constexpr std::string concat(Args &&...args) {
		std::string concatenated_string;
		using std::to_string;
		using mltlib::to_string;
		int unpack[] { (concatenated_string += to_string(args), 0)... };
		static_cast<void>(unpack);
		return concatenated_string;
	}
}