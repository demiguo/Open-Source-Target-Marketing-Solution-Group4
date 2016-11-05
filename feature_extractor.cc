#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include "feature-interface.h"
#include "unit-interface.h"
#include "utils.h"

using namespace std;

namespace open_bracket {

void update_features(const Unit& unit, Feature* feature) {
	feature->unit_id = unit.id;
	feature->user_id = 0;
	feature->features[POPULATION] = unit.population;
	feature->features[RENT_BUDGET] = 10.0;

	// TODO: collect actual label.
	feature->label = 2.0 * (1.0 / (1.0 + exp(-unit.population / 2000.0)) - 0.5);
}

void extract_features() {
	// Load units from file.
	vector<Unit> units;
	load_from_file(unit_filename, &units);

	// Load features from file.
	vector<Feature> features;
	load_from_file(feature_filename, &features);

	map<int64_t, Unit> id_to_units;
	map<int64_t, Feature> id_to_features;
	for (const auto& unit : units) {
		id_to_units[unit.id] = unit;
	}
	for (const auto& feature : features) {
		id_to_features[feature.unit_id] = feature;
	}
	for (const auto& unit : units) {
		update_features(unit, &id_to_features[unit.id]);
	}

	// Save features to file.
	features.clear();
	for (const auto& feature : id_to_features) {
		features.push_back(feature.second);
	}
	write_to_file(feature_filename, features);
}

}  // namespace 

int main() {
	open_bracket::extract_features();
	return 0;
}
