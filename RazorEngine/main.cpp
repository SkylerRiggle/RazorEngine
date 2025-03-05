#include "src/dbg/Logger.h"

#include "src/ecs/Types.h"
#include "src/ecs/Registry.h"

int main(void) {
	rz::LogInfo() << "hello, world!" << std::endl;
	return 0;
}