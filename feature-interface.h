#ifndef FEATURE_INTERFACE_H
#define FEATURE_INTERFACE_H

#include <cinttypes>
#include <cstdint>
#include <string>

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

	// first unit, then features, then label
	std::string serialize_to_string() const { 
		std::string ans = "";
		ans += //serialize unit
		ans += " ";
		for (int i = 0; i < NUM_FEATURES; ++i) {
			ans += to_string(features[i]);
			ans += " ";
		}

		ans += to_string(label);
		return ans;
	}

	void parse_from_string(std::string) {
		
	}
};

#endif  // FEATURE_INTERFACE_H
