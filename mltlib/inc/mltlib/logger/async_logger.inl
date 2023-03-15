#pragma once

#ifndef MLTLIB_HEADER_ONLY
#	include <mltlib/logger/async_logger.hpp>
#endif // !MLTLIB_HEADER_ONLY

namespace mltlib::logger {
	MLTLIB_INLINE async_logger::async_logger(const std::string &name)
		: logger(name), m_thread_pool(1) {}
}