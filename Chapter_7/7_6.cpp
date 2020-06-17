
#if 1
#include <iostream>
#include <sstream>
#include <string.h>
#include <memory>
#include <functional>

namespace android {
	namespace base {
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
		TypeName(const TypeName&) = delete;      \
		void operator=(const TypeName&) = delete

#define SEVERITY_LAMBDA(severity) ([&]() {    \
		using ::android::base::VERBOSE;             \
		using ::android::base::DEBUG;               \
		using ::android::base::INFO;                \
		using ::android::base::WARNING;             \
		using ::android::base::ERROR;               \
		using ::android::base::FATAL_WITHOUT_ABORT; \
		using ::android::base::FATAL;               \
		return (severity); }())

#define _LOG_TAG_INTERNAL "ANDROID_CPP"

#define LOG_STREAM(severity)                                                                    \
		::android::base::LogMessage(__FILE__, __LINE__, SEVERITY_LAMBDA(severity), _LOG_TAG_INTERNAL, \
				-1)                                                               \
		.stream()

#define LOG(severity) LOG_STREAM(severity)

		enum LogSeverity {
			VERBOSE,
			DEBUG,
			INFO,
			WARNING,
			ERROR,
			FATAL_WITHOUT_ABORT,  
			FATAL,
		};

		enum LogId {
			DEFAULT,
			MAIN,
			SYSTEM,
			RADIO,
			CRASH,
		};

		using LogFunction = std::function<void(LogId, LogSeverity, const char*, const char*,
				unsigned int, const char*)>;

		static const char* GetFileBasename(const char* file) {
			const char* last_slash = strrchr(file, '/');
			if (last_slash != nullptr) {
				return last_slash + 1;
			}
			return file;
		}

		void StdioLogger(LogId, LogSeverity severity, const char* tag, const char* file,
				unsigned int line, const char* message) {
			fprintf(stdout, "%s : %s, %u, %s\n", tag, file, line, message);
		}

		static LogFunction& Logger() {
			static auto& logger = *new LogFunction(StdioLogger);
			return logger;
		}

		class LogMessageData;
		class LogMessage {
			public:
				// LogId has been deprecated, but this constructor must exist for prebuilts.
				LogMessage(const char* file, unsigned int line, LogId, LogSeverity severity, const char* tag,
						int error);
				LogMessage(const char* file, unsigned int line, LogSeverity severity, const char* tag, int error);

				~LogMessage();

				// Returns the stream associated with the message, the LogMessage performs
				// output when it goes out of scope.
				std::ostream& stream();

				// The routine that performs the actual logging.
				static void LogLine(const char* file, unsigned int line, LogSeverity severity, const char* tag,
						const char* msg);

			private:
				const std::unique_ptr<LogMessageData> data_;

				DISALLOW_COPY_AND_ASSIGN(LogMessage);
		};
		class LogMessageData {
			public:
				LogMessageData(const char* file, unsigned int line, LogSeverity severity, const char* tag,
						int error)
					: file_(GetFileBasename(file)),
					line_number_(line),
					severity_(severity),
					tag_(tag),
					error_(error) {}

				const char* GetFile() const {
					return file_;
				}

				unsigned int GetLineNumber() const {
					return line_number_;
				}

				LogSeverity GetSeverity() const {
					return severity_;
				}

				const char* GetTag() const { return tag_; }

				int GetError() const {
					return error_;
				}

				std::ostream& GetBuffer() {
					return buffer_;
				}

				std::string ToString() const {
					return buffer_.str();
				}

			private:
				std::ostringstream buffer_;
				const char* const file_;
				const unsigned int line_number_;
				const LogSeverity severity_;
				const char* const tag_;
				const int error_;

				DISALLOW_COPY_AND_ASSIGN(LogMessageData);
		};

		LogMessage::LogMessage(const char* file, unsigned int line, LogId, LogSeverity severity,
				const char* tag, int error)
			: LogMessage(file, line, severity, tag, error) {}

		LogMessage::LogMessage(const char* file, unsigned int line, LogSeverity severity, const char* tag,
				int error)
			: data_(new LogMessageData(file, line, severity, tag, error)) {}

		LogMessage::~LogMessage() {

			if (data_->GetError() != -1) {
				data_->GetBuffer() << ": " << strerror(data_->GetError());
			}

			std::string msg(data_->ToString());

			LogLine(data_->GetFile(), data_->GetLineNumber(), data_->GetSeverity(), data_->GetTag(),
					msg.c_str());
		}

		std::ostream& LogMessage::stream() {
			return data_->GetBuffer();
		}

		void LogMessage::LogLine(const char* file, unsigned int line, LogSeverity severity, const char* tag,
				const char* message) {
			Logger()(DEFAULT, severity, tag, file, line, message);
		}
	}
}

int main() 
{
	LOG(ERROR) << "Log Test!!!";
	return 0;
}

#endif
