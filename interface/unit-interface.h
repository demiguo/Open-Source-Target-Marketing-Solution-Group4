#ifndef UNIT_INTERFACE_H
#define UNIT_INTERFACE_H

#include <cinttypes>
#include <cstdint>
#include <string>
#include <sstream>

std::vector<std::string> generate_location_s_query(const std::string& location) {
	std::vector<std::string> s_query;
	const int length = location.length();
	for (int i = 0; i <= length; ++i) {
		s_query.push_back("l" + std::to_string(i) + "_" + location.substr(0, i));
	}
	return s_query;	
}

struct SQueryIndex {
	std::map<std::string, int64_t> num_contents;

	std::string serialize_to_string() const {
		std::ostringstream sout;
		sout << num_contents.size();
		for (const auto& content : num_contents) {
			sout << " " << content.first << " " << content.second;
		}
		sout.flush();
		return sout.str();
	}
	void parse_from_string(const std::string& s) {
		std::istringstream sin(s);
		int num_lines;
		sin >> num_lines;
		for (int i = 0; i < num_lines; ++i) {
			std::string s_query;
			int64_t count;
			sin >> s_query >> count;
			num_contents[s_query] = count;
		}
	}
};

struct Unit {
	int64_t id;
	std::string display_name;
    int64_t population = 0;
    std::string location;
    int64_t total_housing_units = 0;
    int64_t occupied = 0;
    int64_t vacant = 0;
    double area = 0;
    double length = 0;

    double lat = 0, lng = 0;

	std::string serialize_to_string() const {
	    return std::to_string(id) + " " + display_name + " " +
	      	   std::to_string(population) + " " + location + " " +
	      std::to_string(total_housing_units) + " " + std::to_string(occupied) +
	      " " + std::to_string(vacant) + " " + std::to_string(area) + " " +
	      std::to_string(length) + " " + std::to_string(lat) + " " + std::to_string(lng);
	}
	void parse_from_string(const std::string& s) {
		std::istringstream sin(s);
		sin >> id >> display_name >> population >> location >> total_housing_units
		  >> occupied >> vacant >> area >> length >> lat >> lng;
	}
	std::vector<std::string> generate_s_query() const {
		return generate_location_s_query(location);
	}
};

#endif  // UNIT_INTERFACE_H
