#pragma once

#include <mltlib/common.hpp>

#include <string>
#include <cstdio>

namespace mltlib {
	MLTLIB_INLINE std::string read_file_to_buffer(const std::string &filePath);
	MLTLIB_INLINE void write_to_file(FILE *output, const std::string &str);
}

#ifdef MLTLIB_HEADER_ONLY
#	include <mltlib/file.inl>
#endif // MLTLIB_HEADER_ONLY