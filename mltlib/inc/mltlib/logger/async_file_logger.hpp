#pragma once

#include <mltlib/common.hpp>
#include <mltlib/logger/async_logger.hpp>
#include <mltlib/file.hpp>

namespace mltlib::logger {
	class MLTLIB_API async_file_logger : public async_logger {
	public:
		MLTLIB_INLINE async_file_logger(const std::string &name, FILE *output = stdout);
		MLTLIB_INLINE virtual ~async_file_logger() = default;

	protected:
		FILE *m_output;

		MLTLIB_INLINE virtual void _log(const std::string &msg) const override;
	};
}

#ifdef MLTLIB_HEADER_ONLY
#	include <mltlib/logger/async_file_logger.inl>
#endif // MLTLIB_HEADER_ONLY