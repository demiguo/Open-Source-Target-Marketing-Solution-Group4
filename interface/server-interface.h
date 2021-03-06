#ifndef SERVER_INTERFACE_H
#define SERVER_INTERFACE_H

#include "unit-interface.h"

#include <vector>

struct Request {
	int num_results = 10;
	std::string query_location;
};

struct Response {
	std::vector<Unit> units;
};

#endif  // SERVER_INTERFACE_H
