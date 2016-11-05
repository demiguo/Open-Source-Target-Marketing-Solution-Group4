#include<fstream>
#include<istream>
#include<iostream>
#include<string>
#include<bits/stdc++.h>
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
  std::fstream data;
  data.open("Census_Housing_Units.csv");
  
  std::freopen("units.out", "w", stdout);
  
  std::string s; std::getline(data, s);
  
  std::map<int, Unit> units;
  while(true){
    std::getline(data, s);
    if(s.length() == 0) break;
    std::vector<std::string> fields = tokenize(s);
    Unit u;
    u.id = stoi(fields[0]);
    u.display_name = fields[2];
    units[u.id] = u;
  }
  for(auto u : units){
    std::cout << u.second.serialize_to_string() << "\n";
  }
}
