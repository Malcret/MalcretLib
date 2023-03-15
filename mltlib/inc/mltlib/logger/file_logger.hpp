#pragma once

#include <mltlib/logger/logger.hpp>
#include <mltlib/file.hpp>

namespace mltlib::logger {
	class MLTLIB_API file_logger : public logger {
	public:
		MLTLIB_INLINE file_logger(const std::string &name, FILE *output = stdout);
		MLTLIB_INLINE virtual ~file_logger() = default;

	protected:
		FILE *m_output;

		MLTLIB_INLINE void _log(const std::string &msg) const override;
	};
}

#ifdef MLTLIB_HEADER_ONLY
#	include <mltlib/logger/file_logger.inl>
#endif // MLTLIB_HEADER_ONLY