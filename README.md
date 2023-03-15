# MalcretLib
General purpose library for C++20 or higher only.

### Contains :
- A simple, fast and thread safe logger, a 100'000 log in about 3s on my computer and a little less for the async implementation.
- A simple thread pool.
- Some quality of life functions.
- More to come in the future (I'm writing them when I need them for other project).

### Logger usage example :

```
#include <mltlib/logger/file_logger.hpp>

namespace mltlog = mltlib::logger;

int main() {
	mltlog::file_logger logger("file_logger");
	logger.set_severity_filter(mltlog::severity_level::LOG_SEVERITY_TRACE);

	for (int i = 0; i < 100'000; ++i) {
		logger.log(mltlog::severity_level::LOG_SEVERITY_TRACE, "iteration : ", i);
	}

	return 0;
}
```

Output :

```
[10:38:17] file_logger, TRACE: iteration : 0
...
[10:38:19] file_logger, TRACE: iteration : 99999
```

### Async logger usage example (using the included thread pool) :

```
#include <mltlib/logger/async_file_logger.hpp>

namespace mltlog = mltlib::logger;

int main() {
	mltlog::async_file_logger logger("Logger");
	logger.set_severity_filter(mltlog::severity_level::LOG_SEVERITY_TRACE);

	for (int i = 0; i < 100'000; ++i) {
		logger.async_log(mltlog::severity_level::LOG_SEVERITY_TRACE, "iteration ", i);
	}

	return 0;
}
```

Output :

```
[10:38:17] async_file_logger, TRACE: iteration : 0
...
[10:38:19] async_file_logger, TRACE: iteration : 99999
```