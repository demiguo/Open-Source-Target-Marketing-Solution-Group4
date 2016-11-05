#ifndef MODEL_INTERFACE_H
#define MODEL_INTERFACE_H

#include <string>

struct Model {
	std::string model_name;

	std::string serialize_to_string() const { return ""; }
	void parse_from_string(std::string) {}
};

#endif  // MODEL_INTERFACE_H
