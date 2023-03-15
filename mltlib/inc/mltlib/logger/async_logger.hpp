#pragma once

#include <mltlib/logger/logger.hpp>
#include <mltlib/thread_pool.hpp>

namespace mltlib::logger {
	class MLTLIB_API async_logger : public logger {
	public:
		MLTLIB_INLINE async_logger(const std::string &name);
		MLTLIB_INLINE virtual ~async_logger() = default;

		template<typename... Args>
		MLTLIB_INLINE void async_log(severity_level severity, Args &&...args) {
			m_thread_pool.queue([&, args...]() { this->log(severity, args...); });
		}

	protected:
		thread_pool m_thread_pool;
	};
}

#ifdef MLTLIB_HEADER_ONLY
#	include <mltlib/logger/async_logger.inl>
#endif // MLTLIB_HEADER_ONLY