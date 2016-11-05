#include <iostream>
#include <string>
#include <vector>
#include "feature-interface.h"
#include "unit-interface.h"
#include "utils.h"

using namespace std;

namespace open_bracket {

void update_features(const Unit& unit, Feature* feature) {
	feature->unit = unit;
	feature->features[POPULATION] = 100.0;
	feature->features[RENT_BUDGET] = 10.0;
}

void extract_features() {
	// Load units from file.
	vector<Unit> units;
	load_from_file(unit_filename, &units);

	// Load features from file.
	vector<Feature> features;
	load_from_file(feature_filename, &features);

	// Save features to file.
	write_to_file(feature_filename, features);
}

}  // namespace 

int main() {
	open_bracket::extract_features();
	return 0;
}
