#include<fstream>
#include<istream>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include "unit-interface.h"

std::vector<std::string> tokenize(std::string s){
  std::vector<std::string> ans;
  int start = 0;
  for(int i=1;i<=s.length();i++){
    if(i == s.length() || s[i] == ','){
      ans.push_back(s.substr(start, i - start));
      start = i+1;
    }
  }
  return ans;
}

int main(){
  std::fstream housing_data;
  housing_data.open("Census_Housing_Units.csv");
  std::string s; std::getline(housing_data, s);

  std::fstream block_data;//5
  block_data.open("Census_Block_Groups_2010.csv");
  std::getline(block_data, s);
  
  std::freopen("units.out", "w", stdout);
  
  
  std::map<int, Unit> units;

  
  
  while(true){
    std::getline(housing_data, s);
    if(s.length() == 0) break;
    std::vector<std::string> fields = tokenize(s);
    Unit u;
    u.id = stoi(fields[0]);
    u.display_name = fields[2];
    units[u.id] = u;
  }
  while(true){
    std::getline(block_data, s);
    if(s.length() == 0) break;
    std::vector<std::string> fields = tokenize(s);
    units[stoi(fields[0])].population = stoi(fields[5]);
  }
  for(auto u : units){
    std::cout << u.second.serialize_to_string() << "\n";
  }
}
