#include <iostream>
#include <string>
#include <vector>
#include "feature-interface.h"
#include "unit-interface.h"

using namespace std;

namespace open_bracket {
namespace {
const string unit_filename = "";
const string feature_filename = "";
}

void update_features(const Unit& unit, Feature* feature) {
	feature->unit = unit;
	feature->features[POPULATION] = 100.0;
}

void extract_features() {
	// Load units from file.
	// Load features from file.

	// Save features to file.
}

}  // namespace 

int main() {
	open_bracket::extract_features();
	return 0;
}
