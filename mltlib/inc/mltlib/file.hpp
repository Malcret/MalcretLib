#pragma once

#include <mltlib/common.hpp>

#include <string>

namespace mltlib {
	MLTLIB_INLINE std::string read_file_to_buffer(const std::string &filePath);
}

#ifdef MLTLIB_HEADER_ONLY
#	include <mltlib/file.inl>
#endif // MLTLIB_HEADER_ONLY