#include <mltlib/logger/file_logger.hpp>
#include <mltlib/logger/async_file_logger.hpp>

#include <chrono>
#include <iostream>

namespace mltlog = mltlib::logger;

constexpr size_t ITERATIONS = 100'000;

double test_file_logger(size_t iterations) {
	const auto start = std::chrono::high_resolution_clock::now();
	mltlog::file_logger logger("file_logger");
	logger.set_severity_filter(mltlog::severity_level::LOG_SEVERITY_TRACE);

	for (size_t i = 0; i < iterations; ++i) {
		logger.log(mltlog::severity_level::LOG_SEVERITY_TRACE, "iteration ", i);
	}
	const auto end = std::chrono::high_resolution_clock::now();

	return std::chrono::duration<double, std::milli>(end - start).count();
}

double test_async_file_logger(size_t iterations) {
	const auto start = std::chrono::high_resolution_clock::now();
	{
		mltlog::async_file_logger logger("async_file_logger");
		logger.set_severity_filter(mltlog::severity_level::LOG_SEVERITY_TRACE);

		for (size_t i = 0; i < iterations; ++i) {
			logger.async_log(mltlog::severity_level::LOG_SEVERITY_TRACE, "iteration ", i);
		}
	}
	const auto end = std::chrono::high_resolution_clock::now();

	return std::chrono::duration<double, std::milli>(end - start).count();
}

int main() {
	const double file_logger_time = test_file_logger(ITERATIONS);
	const double async_file_logger_time = test_async_file_logger(ITERATIONS);

	std::cout << "File logger took = " << file_logger_time << "ms for " << ITERATIONS << " iterations\n";
	std::cout << "Async file logger took = " << async_file_logger_time << "ms for " << ITERATIONS << " iterations\n";

	return 0;
}