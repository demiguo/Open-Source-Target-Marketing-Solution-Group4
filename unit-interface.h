#ifndef UNIT_INTERFACE_H
#define UNIT_INTERFACE_H

#include <cinttypes>
#include <cstdint>
#include <string>

struct Unit {
	int64_t id;
	std::string display_name;
};

#endif  // UNIT_INTERFACE_H
