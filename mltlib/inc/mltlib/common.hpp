#pragma once

#ifdef _MSVC_LANG
#	if _MSVC_LANG < 202002L
#		error Please compile with C++20 or higher
#	endif // _MSVC_LANG < 202002L
#else // !_MSVC_LANG
#	if __cplusplus < 202002L
#		error Please compile with C++20 or higher
#	endif // __cplusplus < 202002L
#	define __forceinline __attribute__((always_inline))
#endif // _MSVC_LANG

#ifndef MLTLIB_HEADER_ONLY
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
#	define MLTLIB_FORCE_INLINE
#else // MLTLIB_HEADER_ONLY
#	define MLTLIB_API
#	define MLTLIB_HEADER_ONLY
#	define MLTLIB_INLINE inline
#	define MLTLIB_FORCE_INLINE __forceinline
#endif // !MLTLIB_HEADER_ONLY