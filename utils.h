#ifndef UTIL_INTERFACE_H
#define UTIL_INTERFACE_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <map>
#include <string.h>
#include <istream>

#include "feature-interface.h"
#include "model-interface.h"
#include "server-interface.h"
#include "unit-interface.h"

namespace open_bracket {
namespace {

const int max_length = (1 << 20);
char line[max_length];

}

extern const std::string unit_squery_index_filename = "data/squery_index.dat";
extern const std::string unit_filename_prefix = "data/units.dat.";
extern const std::string model_file = "data/models.dat";
extern const std::string feature_filename = "data/training_data.dat";

std::string unit_filename(const std::string& s_query) {
	return unit_filename_prefix + s_query;
}

template<class T>
bool load_from_file(const std::string& file, std::vector<T>* data) {
	FILE *f = fopen(file.c_str(), "r");
	if (f == nullptr) return false;
	while (fgets(line, 1 << 20, f) != nullptr) {
		data->push_back(T());
		data->back().parse_from_string(line);
	}
	fclose(f);
	printf("Load %d from file %s.\n", (int)data->size(), file.c_str());
	return true;
}

template<class T>
bool load_from_file(const std::string& file, T* data) {
	FILE *f = fopen(file.c_str(), "r");
	if (f == nullptr) return false;
	fgets(line, 1 << 20, f);
	data->parse_from_string(line);
	fclose(f);
	printf("Read data from file %s\n", file.c_str());
	return true;
}

template<class T>
bool write_to_file(const std::string& file, const std::vector<T>& data) {
	FILE *f = fopen(file.c_str(), "w");
	if (f == nullptr) { 
		printf("Fail to write file %s\n", file.c_str());
		return false;
	}
	for (const auto& d : data) {
		fprintf(f, "%s\n", d.serialize_to_string().c_str());
	}
	fclose(f);
	printf("Write %d to file %s.\n", (int)data.size(), file.c_str());
	return true;
}

template<class T>
bool write_to_file(const std::string& file, const T& data) {
	FILE *f = fopen(file.c_str(), "w");
	if (f == nullptr) { 
		printf("Fail to write file %s\n", file.c_str());
		return false;
	}
	fprintf(f, "%s\n", data.serialize_to_string().c_str());
	fclose(f);
	printf("Write data to file %s\n", file.c_str());
	return true;
}

}

#endif  // UTIL_INTERFACE_H
