#include <fstream>
#include <istream>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "unit-interface.h"
#include "utils.h"

using namespace std;

std::vector<std::string> tokenize(std::string s){
  std::vector<std::string> ans;
  int start = 0;
  for (int i = 1; i <= s.length(); i++) {
    if (i == s.length() || s[i] == ',') {
      ans.push_back(s.substr(start, i - start));
      start = i+1;
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

  std::map<int, Unit> units;
  
  while (true){
    std::getline(housing_data, s);
    if(s.length() == 0) break;
    std::vector<std::string> fields = tokenize(s);
    Unit u;
    u.id = stoi(fields[0]);
    u.display_name = fields[2];
    u.location = fields[2];
    units[u.id] = u;
  }
  while(true){
    std::getline(block_data, s);
    if(s.length() == 0) break;
    std::vector<std::string> fields = tokenize(s);
    units[stoi(fields[0])].population = stoi(fields[5]);
  }

  std::vector<Unit> units_sorted_by_ids;
  for (const auto& unit : units) {
    units_sorted_by_ids.push_back(unit.second);
  }
  open_bracket::write_units(units_sorted_by_ids);
  return 0;
}
