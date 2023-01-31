#pragma once

// TODO !
// use fwrite to output to stdout
// use WriteFile with windows if issues

#include <iostream>
#include <thread>
#include <mutex>
#include <Windows.h>

namespace mltlib {
	namespace logger {
		enum class severity {
			LOG_SEVERITY_TRACE = 0,
			LOG_SEVERITY_DEBUG = 1,
			LOG_SEVERITY_INFO = 2,
			LOG_SEVERITY_WARNING = 3,
			LOG_SEVERITY_ERROR = 4,
			LOG_SEVERITY_CRITICAL = 5
		};

		template<typename CharT, typename Traits = std::char_traits<CharT>>
		class basic_ostream_logger {
		private:
			enum class color;
		public:
			basic_ostream_logger(std::basic_ostream<CharT, Traits> &ostream, const std::string &name = "Log", bool is_console_logger = true)
				: m_ostream(ostream), m_name(name), m_is_console_logger(is_console_logger), m_hConsole(nullptr), m_original_attributes(0)
				, m_severity_filter(severity::LOG_SEVERITY_INFO), m_working_threads(0) {
				if (m_is_console_logger) {
					set_console_logger();
				}
			}
			basic_ostream_logger(std::basic_ostream<CharT, Traits> &ostream, bool is_console_logger)
				: m_ostream(ostream), m_name("Log"), m_is_console_logger(is_console_logger), m_hConsole(nullptr), m_original_attributes(0)
				, m_severity_filter(severity::LOG_SEVERITY_INFO), m_working_threads(0) {
				if (m_is_console_logger) {
					set_console_logger();
				}
			}
			~basic_ostream_logger() {
				std::mutex m;
				std::unique_lock<std::mutex> lock(m);
				m_mutex_condition.wait(lock, [this]() { return this->m_working_threads == 0; });
			}

			template<typename... Args>
			void log(severity severity, const Args &...args) {
				if (severity >= m_severity_filter) {
					m_mutex.lock();
					//if (m_is_console_logger) {
					//	change_color(severity_to_color(severity));
					//}
					((m_ostream << "[date] (" << m_name << ") " << severity_to_str(severity) << ": ") << ... << args) << "\n";
					//if (m_is_console_logger) {
					//	reset_color();
					//}
					m_mutex.unlock();
				}
			}

			template<typename... Args>
			std::thread log_async(severity severity, const Args &...args) {
				std::thread t([this, severity, &args...]() { ++this->m_working_threads; this->log(severity, args...); --this->m_working_threads; this->m_mutex_condition.notify_all(); });
				t.detach();
				return t;
			}

			const std::string &get_name() const {
				return m_name;
			}

			void set_severity_filter(severity severity_filter) {
				m_severity_filter = severity_filter;
			}
			severity get_severity_filter() const {
				return m_severity_filter;
			}

		private:
			std::basic_ostream<CharT, Traits> &m_ostream;
			const std::string m_name;
			const bool m_is_console_logger;
			HANDLE m_hConsole;
			short m_original_attributes;
			std::mutex m_mutex;
			severity m_severity_filter;
			std::atomic<unsigned long> m_working_threads;
			std::condition_variable m_mutex_condition;

			void set_console_logger() {
				m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
				CONSOLE_SCREEN_BUFFER_INFO info;
				GetConsoleScreenBufferInfo(m_hConsole, &info);
				m_original_attributes = info.wAttributes;
			}

			void change_color(color color) {
				SetConsoleTextAttribute(m_hConsole, 0xFFF0 & m_original_attributes | (short)color);
			}

			void reset_color() {
				SetConsoleTextAttribute(m_hConsole, m_original_attributes);
			}

			color severity_to_color(severity severity) const {
				switch (severity) {
					case severity::LOG_SEVERITY_DEBUG:
						return color::WHITE;
					case severity::LOG_SEVERITY_TRACE:
						return color::GREY;
					case severity::LOG_SEVERITY_INFO:
						return color::GREEN;
					case severity::LOG_SEVERITY_WARNING:
						return color::YELLOW;
					case severity::LOG_SEVERITY_ERROR:
						return color::LIGHT_RED;
					case severity::LOG_SEVERITY_CRITICAL:
						return color::RED;
					default:
						return color::WHITE;
				}
			}

			std::string severity_to_str(severity severity) const {
				switch (severity) {
					case severity::LOG_SEVERITY_DEBUG:
						return std::move("DEBUG");
					case severity::LOG_SEVERITY_TRACE:
						return std::move("TRACE");
					case severity::LOG_SEVERITY_INFO:
						return std::move("INFO");
					case severity::LOG_SEVERITY_WARNING:
						return std::move("WARNING");
					case severity::LOG_SEVERITY_ERROR:
						return std::move("ERROR");
					case severity::LOG_SEVERITY_CRITICAL:
						return std::move("CRITICAL");
					default:
						return std::move("UNKNOW_SEVERITY");
				}
			}

			enum class color {
				BLACK = 0,
				BLUE = 1,
				GREEN = 2,
				AQUA = 3,
				RED = 4,
				PURPLE = 5,
				YELLOW = 6,
				WHITE = 7,
				GREY = 8,
				LIGHT_BLUE = 9,
				LIGHT_GREEN = 10,
				LIGHT_AQUA = 11,
				LIGHT_RED = 12,
				LIGHT_PURPLE = 13,
				LIGHT_YELLOW = 14,
				BRIGHT_WHITE = 15
			};
		};

		using ostream_logger = basic_ostream_logger<char>;
	} // namespace logger
} // namespace mltlib

namespace mltlog = mltlib::logger;