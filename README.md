# MalcretLib
General purpose library for C++20 or higher only.

### Contains :
- A simple, fast and thread safe logger, about a 100'000 log in less then 3s on my computer.
- A simple thread pool.
- Some quality of life functions.
- More to come in the future (I'm writing them when I need them for other project).

### Logger usage example :

```
#include <mltlib/logger/file_logger.hpp>

namespace mltlog = mltlib::logger;

int main() {
	mltlog::file_logger logger;
	logger.set_severity_filter(mltlog::severity_level::LOG_SEVERITY_TRACE);

	for (int i = 0; i < 100'000; ++i) {
		logger.log(mltlog::severity_level::LOG_SEVERITY_TRACE, "iteration : ", i);
	}

	return 0;
}
```

### Async logger usage example (using the included thread pool) :

```
#include <mltlib/logger/file_logger.hpp>
#include <mltlib/thread_pool.hpp>

namespace mltlog = mltlib::logger;

int main() {
	mltlog::file_logger logger;
	logger.set_severity_filter(mltlog::severity_level::LOG_SEVERITY_TRACE);

	mltlib::thread_pool pool(1);

	for (int i = 0; i < 100'000; ++i) {
		pool.queue([&logger, i] {
			logger.log(mltlog::severity_level::LOG_SEVERITY_TRACE, "iteration : ", i);
		});
	}

	pool.stop();

	return 0;
}
```