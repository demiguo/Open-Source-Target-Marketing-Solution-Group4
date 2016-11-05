#ifndef FEATURE_INTERFACE_H
#define FEATURE_INTERFACE_H

#include <cinttypes>
#include <cstdint>
#include <string>
#include <sstream>
#include <istream>
#include <vector>
#include <cmath>

#include "unit-interface.h"

enum {
	POPULATION = 0,
	RENT_BUDGET = 1,
	NUM_FEATURES,
};

struct Feature {
	int64_t unit_id;
	int64_t user_id;
	std::vector<double> features;
	double label = 0.0;

	Feature() {
		features.resize(NUM_FEATURES);
	}

	void update(const Unit& unit) {
		unit_id = unit.id;
		user_id = 0;
		features[POPULATION] = unit.population;
		features[RENT_BUDGET] = 10.0;

		// TODO: collect actual label.
		label = 2.0 * (1.0 / (1.0 + exp(-unit.population / 2000.0)) - 0.5);
	}

	// first unit, then features, then label
	std::string serialize_to_string() const { 
		std::string ans = "";
		std::ostringstream ss;
		ss << unit_id << ' ' << user_id << ' ';
		for (double d : features)
			ss << d << ' ';
		ss << label;
		ss.flush();
		return ss.str();
	}

	void parse_from_string(std::string s) {
		std::istringstream ss(s);
		ss >> unit_id;
		ss >> user_id;
		features.resize(NUM_FEATURES);
		for (int i = 0; i < NUM_FEATURES; ++i)
			ss >> features[i];
		ss >> label;
	}
};

#endif  // FEATURE_INTERFACE_H
