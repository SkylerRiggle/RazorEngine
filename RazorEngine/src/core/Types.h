#ifndef RZ_CORE_TYPES_H
#define RZ_CORE_TYPES_H

namespace rz {
	typedef char int8;
	typedef short int16;
	typedef int int32;
	typedef long long int int64;

	static_assert(sizeof(int8) == 1, "Type int8 should be 1 byte in length!");
	static_assert(sizeof(int16) == 2, "Type int16 should be 2 bytes in length!");
	static_assert(sizeof(int32) == 4, "Type int32 should be 4 bytes in length!");
	static_assert(sizeof(int64) == 8, "Type int64 should be 8 bytes in length!");

	typedef unsigned char uint8;
	typedef unsigned short uint16;
	typedef unsigned int uint32;
	typedef unsigned long long int uint64;

	static_assert(sizeof(uint8) == 1, "Type uint8 should be 1 byte in length!");
	static_assert(sizeof(uint16) == 2, "Type uint16 should be 2 bytes in length!");
	static_assert(sizeof(uint32) == 4, "Type uint32 should be 4 bytes in length!");
	static_assert(sizeof(uint64) == 8, "Type uint64 should be 8 bytes in length!");
}

#endif // ! RZ_CORE_TYPES_H