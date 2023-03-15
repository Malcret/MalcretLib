#pragma once

#ifndef MLTLIB_HEADER_ONLY
#	include <mltlib/logger/async_file_logger.hpp>
#endif // !MLTLIB_HEADER_ONLY

namespace mltlib::logger {
	MLTLIB_INLINE async_file_logger::async_file_logger(const std::string &name, FILE *output)
		: async_logger(name), m_output(output) {}

	MLTLIB_INLINE void async_file_logger::_log(const std::string &msg) const {
		write_to_file(m_output, msg);
	}
}