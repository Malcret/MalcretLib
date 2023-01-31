#pragma once

#ifdef _MSVC_LANG
#	if _MSVC_LANG < 202002L
#		error Please compile with C++17 or higher
#	endif
#else
#	if __cplusplus < 202002L
#		error Please compile with C++17 or higher
#	endif
#endif

#ifdef MLTLIB_COMPILED_LIB
#	ifdef MLTLIB_HEADER_ONLY
#		error MLTLIB_COMPILED_LIB and MLTLIB_HEADER_ONLY can not be defined as the same time.
#	endif MLTLIB_HEADER_ONLY
#	ifdef MLTLIB_SHARED_LIB
#		ifdef _WIN32
#			ifdef _DLL
#				define MLTLIB_API __declspec(dllexport)
#			else // !_DLL
#				define MLTLIB_API __declspec(import)
#			endif // _DLL
#		else // !_WIN32
#			define MLTLIB_API __attribute__((visibility("default")))
#		endif // _WIN32
#	else // !MLTLIB_SHARED_LIB
#		define MLTLIB_API
#	endif // MLTLIB_SHARED_LIB
#	define MLTLIB_INLINE
#	define MLTLIB_FORCE_INLINE inline
#else // !MLTLIB_COMPILED_LIB
#	define MLTLIB_API
#	define MLTLIB_HEADER_ONLY
#	define MLTLIB_INLINE inline
#	define MLTLIB_FORCE_INLINE inline
#endif // MLTLIB_COMPILED_LIB