#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

#include "../interface/unit-interface.h"
#include "../utils/utils.h"

using namespace std;

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

namespace open_bracket {

namespace {
const int64_t min_num_candidates = 30;
}  // namespace

void write_units(const std::vector<Unit>& units) {
  std::map<std::string, std::vector<const Unit*>> contents;
  for (const auto& unit : units) {
    std::vector<std::string> s_query = unit.generate_s_query();
    for (const auto& s : s_query) {
      contents[s].push_back(&unit);
    }
  }
  SQueryIndex index;
  for (const auto& it : contents) {
    if (it.second.size() >= min_num_candidates) {
      index.num_contents[it.first] = it.second.size();
    }
  }
  write_to_file(unit_squery_index_filename, index);

  for (const auto& content : contents) {
    if (content.second.size() >= min_num_candidates) {
      std::vector<Unit> sub_units;
      for (const auto& unit : content.second) {
        sub_units.push_back(*unit);
      }
      write_to_file(unit_filename(content.first), sub_units);
    }
  }
}

}

int main() {
  std::fstream housing_data;
  housing_data.open("Census_Housing_Units.csv");
  std::string s;
  std::getline(housing_data, s);

  std::fstream block_data;
  block_data.open("Census_Block_Groups_2010.csv");
  std::getline(block_data, s);

  std::fstream zip_code_database;
  zip_code_database.open("zip_code_database.csv");
  std::getline(zip_code_database, s);
  
  std::map<int64_t, Unit> units;
  std::map<int, Unit*> name10_to_units; 

  int64_t total_housing_units = 0;
  int64_t occupied = 0;
  int64_t vacant = 0;
  double area = 0;
  double length = 0;

  while (true) {
    std::getline(housing_data, s);
    if (s.length() == 0) break;
    std::vector<std::string> fields = tokenize(s);
    Unit u;
    u.id = stol(fields[2]);
    u.display_name = fields[2];
    u.location = fields[2];
    u.total_housing_units = stoi(fields[6]);
    u.occupied = stoi(fields[7]);
    u.vacant = stoi(fields[8]);
    u.area = stod(fields[10]);
    u.length = stod(fields[11]);
    // Set default lat/lgn.
    u.lat = 39.324991;
    u.lng = -75.6225381;
    units[u.id] = u;
  }
  printf("Total number of geo-ids = %d\n", (int)units.size());

  // The groups in block_data contain many units
  while (true) {
    std::getline(block_data, s);
    if (s.length() == 0) break;
    std::vector<std::string> fields = tokenize(s);
    const int64_t geo_id = stol(fields[3]);
    if (!units.count(geo_id)) {
      continue;
    }
    Unit* unit = &units[geo_id];
    unit->population = stoi(fields[5]);

    const int name10 = (int)stof(fields[7]);
    name10_to_units[name10] = unit; 
  }
  printf("Total number of name10s = %d\n", (int)name10_to_units.size());

  while (true) {
    std::getline(zip_code_database, s);
    if (s.length() == 0) break;
    std::vector<std::string> fields = tokenize(s);
    int cnt = fields.size();
    std::string val = fields[9];
    if (val.empty()) continue;
    if (val[0] == '"') {
      val = val.substr(0, val.find(","));
      val = val.substr(1);
    }
    const int name10 = (int)stoi(val);
    if (name10_to_units.count(name10)) {
      Unit* unit = name10_to_units[name10];
      unit->lat = stof(fields[12]);
      unit->lng = stof(fields[13]);
    }
  }

  std::vector<Unit> units_sorted_by_ids;
  for (const auto& unit : units) {
    units_sorted_by_ids.push_back(unit.second);
  }
  open_bracket::write_units(units_sorted_by_ids);
  printf("Write %d units\n", (int)units_sorted_by_ids.size());
  return 0;
}
