#ifndef FEATURE_INTERFACE_H
#define FEATURE_INTERFACE_H

#include <cinttypes>
#include <cstdint>
#include <string>

#include "unit-interface.h"

enum {
	POPULATION = 0,
	NUM_FEATURES,
};

struct Feature {
	Unit unit;
	std::vector<double> features;
	double label = 0.0;

	Feature() {
		features.resize(NUM_FEATURES);
	}

	std::string serialize_to_string() const { return ""; }
	void parse_from_string(std::string) {}
};

#endif  // FEATURE_INTERFACE_H
