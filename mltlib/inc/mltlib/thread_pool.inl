#pragma once

#ifndef MLTLIB_HEADER_ONLY
#	include <mltlib/thread_pool.hpp>
#endif // !MLTLIB_HEADER_ONLY

namespace mltlib {
	MLTLIB_INLINE thread_pool::thread_pool(size_t pool_size)
		: m_pool_size(pool_size), m_threads(pool_size), m_should_terminate(false) {
		for (size_t i = 0; i < m_pool_size; ++i) {
			m_threads[i] = std::thread(&thread_pool::loop, this);
		}
	}

	MLTLIB_INLINE thread_pool::~thread_pool() {
		this->stop();
	}

	MLTLIB_INLINE void thread_pool::queue(const std::function<void()> &job) {
		m_mutex.lock();
		m_jobs.push(job);
		m_mutex.unlock();
		m_mutex_condition.notify_one();
	}

	MLTLIB_INLINE void thread_pool::stop() {
		m_should_terminate = true;
		m_mutex_condition.notify_all();
		for (std::thread &active_threads : m_threads) {
			active_threads.join();
		}
		m_threads.clear();
	}

	MLTLIB_INLINE bool thread_pool::busy() const {
		return m_jobs.empty();
	}

	MLTLIB_INLINE void thread_pool::loop() {
		std::function<void()> job;
		while (true) {
			{
				std::unique_lock<std::mutex> lock(m_mutex);
				m_mutex_condition.wait(lock, [this]() { return !m_jobs.empty() || m_should_terminate; });
				if (m_should_terminate && m_jobs.empty()) {
					return;
				}
				job = m_jobs.front();
				m_jobs.pop();
			}
			job();
		}
	}

	MLTLIB_INLINE size_t thread_pool::max_threads() {
		return std::thread::hardware_concurrency();
	}
}