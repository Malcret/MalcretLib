#include <mltlib/logger/file_logger.hpp>
#include <mltlib/thread_pool.hpp>
#include <chrono>
#include <iostream>

namespace mltlog = mltlib::logger;

int main() {
	mltlog::file_logger logger;
	logger.set_severity_filter(mltlog::severity_level::LOG_SEVERITY_TRACE);

	mltlib::thread_pool pool(1);

	auto start = std::chrono::system_clock::now();
	for (int i = 0; i < 100'000; ++i) {
		pool.queue([&logger, i] { logger.log(mltlog::severity_level::LOG_SEVERITY_TRACE, "iteration : ", i); });
		//logger.log(mltlog::severity_level::LOG_SEVERITY_TRACE, "iteration : ", i);
	}
	pool.stop();
	auto end = std::chrono::system_clock::now();

	std::cout << "file logger took : " << std::chrono::duration<double>(end - start) << "\n";

	return 0;
}