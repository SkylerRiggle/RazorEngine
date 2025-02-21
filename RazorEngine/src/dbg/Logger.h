#ifndef RZ_DBG_LOGGER_H
#define RZ_DBG_LOGGER_H

#include <iostream>

namespace rz {
	void SetLogFile(const char* file_path, const bool clear_file);

	std::ostream& LogInfo();
	std::ostream& LogWarning();
	std::ostream& LogError();
	std::ostream& LogSuccess();
}

#endif // ! RZ_DBG_LOGGER_H