#include "Logger.h"

#ifdef RZ_DEBUG

#include <ctime>
#include <fstream>

const char* INFO_TAG = "INFO";
const char* WARN_TAG = "WARNING";
const char* ERROR_TAG = "ERROR";
const char* SUCC_TAG = "SUCCESS";

const char* INFO_COLOR = "\x1b[34m";
const char* WARN_COLOR = "\x1b[33m";
const char* ERROR_COLOR = "\x1b[31m";
const char* SUCC_COLOR = "\x1b[32m";

static bool log_to_file = false;
std::ostream logger = std::ostream(std::cout.rdbuf());

void rz::SetLogFile(const char* file_path, const bool clear_file) {
	static std::ofstream file;

	if (log_to_file) {
		file.close();
		log_to_file = false;
	}

	file.open(
		file_path,
		std::ofstream::out | (clear_file ? std::ofstream::trunc : std::ofstream::app)
	);

	if (!file.is_open()) {
		LogError() << "Failed to open log file: " << file_path << std::endl;
		return;
	}

	log_to_file = true;
	logger.set_rdbuf(file.rdbuf());
}

static std::ostream& InternalLog(const char* tag, const char* color_code) {
	time_t now = time(0);
	struct tm local;

	if (!localtime_s(&local, &now)) {
		char time_buf[22];
		strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S [", &local);
		logger << time_buf;
	}
	else {
		logger << "TIME_ERROR [";
	}

	if (log_to_file) {
		return logger << tag << "]: ";
	}

	return logger << color_code << tag << "\x1b[0m]: ";
}

std::ostream& rz::LogInfo() {
	return InternalLog(INFO_TAG, INFO_COLOR);
}

std::ostream& rz::LogWarning() {
	return InternalLog(WARN_TAG, WARN_COLOR);
}

std::ostream& rz::LogError() {
	return InternalLog(ERROR_TAG, ERROR_COLOR);
}

std::ostream& rz::LogSuccess() {
	return InternalLog(SUCC_TAG, SUCC_COLOR);
}

#else

static std::ostream null_stream(nullptr);

void rz::SetLogFile(const char* file_path, const bool clear_file) {}

std::ostream& rz::LogInfo() { return null_stream; }

std::ostream& rz::LogWarning() { return null_stream; }

std::ostream& rz::LogError() { return null_stream; }

std::ostream& rz::LogSuccess() { return null_stream; }

#endif // RZ_DEBUG