#ifndef SERVER_INTERFACE_H
#define SERVER_INTERFACE_H

#include "unit-interface.h"

#include <vector>

struct Request {
};

struct Response {
	std::vector<Unit> units;
};

#endif  // SERVER_INTERFACE_H
