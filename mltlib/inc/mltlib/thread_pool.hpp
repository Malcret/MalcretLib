#pragma once

#include <mltlib/common.hpp>

#include <thread>
#include <functional>
#include <mutex>
#include <vector>
#include <queue>

namespace mltlib {
	class MLTLIB_API thread_pool {
	public:
		thread_pool(size_t pool_size = max_threads());
		~thread_pool();

		void queue(const std::function<void()> &job);
		void stop();
		bool busy();

		static size_t max_threads();

	private:
		bool m_should_terminate;
		const size_t m_pool_size;
		std::mutex m_mutex;
		std::condition_variable m_mutex_condition;
		std::vector<std::thread> m_threads;
		std::queue<std::function<void()>> m_jobs;

		void loop();
	};
}

#ifdef MLTLIB_HEADER_ONLY
	#include <mltlib/thread_pool.inl>
#endif // MLTLIB_HEADER_ONLY
