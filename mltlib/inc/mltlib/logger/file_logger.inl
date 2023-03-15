#pragma once

#ifndef MLTLIB_HEADER_ONLY
#	include <mltlib/logger/file_logger.hpp>
#endif // !MLTLIB_HEADER_ONLY

namespace mltlib::logger {
	MLTLIB_INLINE file_logger::file_logger(const std::string &name, FILE *output)
		: logger(name), m_output(output) {}

	MLTLIB_INLINE void file_logger::_log(const std::string &msg) const {
		write_to_file(m_output, msg);
	}
}