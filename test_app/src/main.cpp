#include <mltlib/logger/file_logger.hpp>

#include <chrono>
#include <iostream>

namespace mltlog = mltlib::logger;

constexpr int LOGGER_ITERATIONS = 100'000;

double test_logger() {
	mltlog::file_logger logger("Test");
	logger.set_severity_filter(mltlog::severity_level::LOG_SEVERITY_TRACE);

	const auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < LOGGER_ITERATIONS; ++i) {
		logger.log(mltlog::severity_level::LOG_SEVERITY_TRACE, "iteration : ", i);
	}
	const auto end = std::chrono::high_resolution_clock::now();

	return std::chrono::duration<double, std::milli>(end - start).count();
}

int main() {
	//mltlog::file_logger logger;
	//logger.set_severity_filter(mltlog::severity_level::LOG_SEVERITY_TRACE);
	//
	//mltlib::thread_pool pool(1);
	//
	//auto start = std::chrono::system_clock::now();
	//for (int i = 0; i < 100'000; ++i) {
	//	pool.queue([&logger, i] { logger.log(mltlog::severity_level::LOG_SEVERITY_TRACE, "iteration : ", i); });
	//	//logger.log(mltlog::severity_level::LOG_SEVERITY_TRACE, "iteration : ", i);
	//}
	//pool.stop();
	//auto end = std::chrono::system_clock::now();
	//
	//std::cout << "file logger took : " << std::chrono::duration<double>(end - start) << "\n";

	const double logger_time = test_logger();
	std::cout << "Logger took = " << logger_time << "ms\n";

	return 0;
}