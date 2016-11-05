#ifndef UNIT_INTERFACE_H
#define UNIT_INTERFACE_H

#include <cinttypes>
#include <cstdint>
#include <string>

struct Unit {
	int64_t id;
	std::string display_name;

	std::string serialize_to_string() const { return ""; }
	void parse_from_string(std::string) {}
};

#endif  // UNIT_INTERFACE_H
