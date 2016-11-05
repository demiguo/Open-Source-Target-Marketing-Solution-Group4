#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>

#include "../interface/feature-interface.h"
#include "../interface/unit-interface.h"
#include "../utils/utils.h"

using namespace std;

namespace open_bracket {

const int64_t BASE = 10000;

std::vector<std::string> tokenize(std::string s){
  std::vector<std::string> ans;
  int start = 0;
  int depth = 0;
  for (int i = 1; i <= s.length(); i++) {
    if (i == s.length() || (depth == 0 && s[i] == ',')) {
      ans.push_back(s.substr(start, i - start));
      start = i+1;
    } else if (s[i] == '"') {
      depth ^= 1;
    }
  }
  return ans;
}

void load_exteral_demographic_data(const unordered_set<int64_t>& unit_ids, unordered_map<int64_t, vector<double>>* demographic_data) {
	fstream demo_data;
	string s;
  	demo_data.open("DemographicData.csv");
  	std::getline(demo_data, s);
  	std::getline(demo_data, s);

  	unordered_set<int64_t> trimmed_unit_ids;
  	for (int64_t id : unit_ids) {
	  	trimmed_unit_ids.insert(id / BASE);
	}
	while (true) {
	    std::getline(demo_data, s);
	    if (s.length() == 0) break;
	    vector<std::string> fields = tokenize(s);
	    const int64_t geo_id = stol(fields[1]);
	    if (!trimmed_unit_ids.count(geo_id)) continue;
	    vector<double> hidden_features;
	    for (int i = 3; i < fields.size(); ++i) {
	    	const string val = fields[i];
	    	if (val[0] >= '0' && val[0] <= '9') {
	    		hidden_features.push_back(stof(val));
	    	}
	    }
	    (*demographic_data)[geo_id] = hidden_features;
	}
	printf("Load demo data for %d blocks from %d.\n", (int)demographic_data->size(), (int)trimmed_unit_ids.size());
}

void extract_features() {
	// Load units from file.
	SQueryIndex index;
	load_from_file(unit_squery_index_filename, &index);
	unordered_set<int64_t> unit_ids;
	vector<Unit> units;
	for (const auto& content : index.num_contents) {
		vector<Unit> sub_units;
		load_from_file(unit_filename(content.first), &sub_units);
		for (const auto& unit : sub_units) {
			if (unit_ids.count(unit.id)) continue;
			unit_ids.insert(unit.id);
			units.push_back(unit);
		}
	}
	printf("Total number of units = %d\n", (int)units.size());

	unordered_map<int64_t, vector<double>> demographic_data;
	load_exteral_demographic_data(unit_ids, &demographic_data);

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
		vector<double> hidden_features;
		if (demographic_data.count(unit.id / BASE)) {
			hidden_features = demographic_data[unit.id / BASE];
		} else {
			printf("No demographic data found for id = %lld\n", unit.id);
		}
		id_to_features[unit.id].update(unit, hidden_features);
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
