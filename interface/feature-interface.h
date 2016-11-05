#ifndef FEATURE_INTERFACE_H
#define FEATURE_INTERFACE_H

#include <cinttypes>
#include <cstdint>
#include <string>
#include <sstream>
#include <istream>
#include <vector>
#include <cmath>
#include <map>

#include "unit-interface.h"

enum {
	POPULATION = 0,
	RENT_BUDGET = 1,
	TOTAL_HOUSING_UNITS = 2,
	OCCUPIED = 3,
	VACANT = 4,
	AREA = 5,
	LENGTH = 6,
	NUM_FEATURES,
};
extern const int NUM_HIDDEN_FEATURES = 361;

struct Feature {
	int64_t unit_id;
	int64_t user_id;
	std::vector<double> features;
	std::vector<double> hidden_features;
	double label = 0.0;

	Feature() {
		features.resize(NUM_FEATURES);
	}

	void update(const Unit& unit, const std::vector<double>& _hidden_features) {
		unit_id = unit.id;
		user_id = 0;
		features[POPULATION] = unit.population;
		features[TOTAL_HOUSING_UNITS] = unit.total_housing_units;
		features[OCCUPIED] = unit.occupied;
		features[VACANT] = unit.vacant;
		features[AREA] = unit.area;
		features[LENGTH] = unit.length;

		// TODO: load real rent budget.
		features[RENT_BUDGET] = 10.0;

		hidden_features = _hidden_features;

		// TODO: collect actual label.
		label = 2.0 * (1.0 / (1.0 + exp(-unit.total_housing_units / 10.0)) - 0.5);
	}

	// first unit, then features, then label
	std::string serialize_to_string() const { 
		std::string ans = "";
		std::ostringstream ss;
		ss << unit_id << ' ' << user_id << ' ';
		ss << features.size() << ' ';
		for (double d : features) {
			ss << d << ' ';
		}
		ss << hidden_features.size() << ' ';
		for (double d : hidden_features) {
			ss << d << ' ';
		}
		ss << label;
		ss.flush();
		return ss.str();
	}

	void parse_from_string(std::string s) {
		std::istringstream ss(s);
		ss >> unit_id;
		ss >> user_id;
		int num_features;
		ss >> num_features;
		if (num_features != NUM_FEATURES) {
			printf("Bad number of features %d %d.\n", num_features, (int)NUM_FEATURES);
			return;
		}
		features.resize(NUM_FEATURES);
		for (int i = 0; i < NUM_FEATURES; ++i) {
			ss >> features[i];
		}
		int num_hidden_features;
		ss >> num_hidden_features;
		if (num_hidden_features != NUM_HIDDEN_FEATURES) {
			printf("Bad number of hidden features %d %d.\n", num_hidden_features, (int)NUM_HIDDEN_FEATURES);
			return;
		}
		hidden_features.resize(NUM_HIDDEN_FEATURES);
		for (int i = 0; i < NUM_HIDDEN_FEATURES; ++i) {
			ss >> hidden_features[i];
		}
		ss >> label;
	}
};

#endif  // FEATURE_INTERFACE_H
