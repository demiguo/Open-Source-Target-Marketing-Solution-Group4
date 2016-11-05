#ifndef UNIT_INTERFACE_H
#define UNIT_INTERFACE_H

#include <cinttypes>
#include <cstdint>
#include <string>
#include <vector>


struct Unit {
  int64_t id;
  std::string display_name;
  int64_t population;

  std::string serialize_to_string() const {
    return std::to_string(id) + " " + display_name + " " +
      std::to_string(population);
  }
  void parse_from_string(std::string s) {
    std::vector<std::string> ans;
    int start = 0;
    for(int i=1;i<=s.length();i++){
      if(i == s.length() || s[i] == ' '){
	ans.push_back(s.substr(start, i - start));
	start = i+1;
      }
    }
    id = stoi(ans[1]);
    display_name = ans[1];
    population = stoi(ans[2]);
    return;
  }
};

#endif  // UNIT_INTERFACE_H
