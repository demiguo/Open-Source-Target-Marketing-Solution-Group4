#ifndef UTIL_INTERFACE_H
#define UTIL_INTERFACE_H

#include <string>
#include <vector>

#include "feature-interface.h"
#include "model-interface.h"
#include "server-interface.h"
#include "unit-interface.h"

namespace open_bracket {

extern const std::string model_file = "models.out";
extern const std::string unit_filename = "units.out";
extern const std::string feature_filename = "features.out";

template<class T>
bool load_from_file(const std::string& file, std::vector<T>* data) {
	return false;
}

template<class T>
bool load_from_file(const std::string& file, T* data) {
	return false;
}

template<class T>
bool write_to_file(const std::string& file, const std::vector<T>& data) {
	return false;
}

template<class T>
bool write_to_file(const std::string& file, const T& data) {
	return false;
}

}

#endif  // UTIL_INTERFACE_H
