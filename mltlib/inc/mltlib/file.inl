#pragma once

#ifndef MLTLIB_HEADER_ONLY
#	include <mltlib/file.hpp>
#endif // !MLTLIB_HEADER_ONLY

#include <fstream>
#include <iostream>

namespace mltlib {
	MLTLIB_INLINE std::string read_file_to_buffer(const std::string &filePath) {
		// Open file
		std::ifstream file(filePath, std::ios::binary);
		if (!file.is_open()) {
			std::cerr << "ERROR: Failed to open \"" << filePath << "\" !\n";
		}

		// Get file size and allocate buffer memory
		std::string buffer;
		file.seekg(0, std::ios::end);
		const size_t size = file.tellg();
		buffer.resize(size);

		// Read file to buffer
		file.seekg(0);
		file.read(buffer.data(), size);

		file.close();

		return buffer;
	}

	MLTLIB_INLINE void write_to_file(FILE *output, const std::string &str) {
		fwrite(str.c_str(), sizeof(char), str.size(), output);
		fflush(output);
	}
}