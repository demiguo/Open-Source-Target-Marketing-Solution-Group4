#include <iostream>
#include <vector>
#include "server-interface.h"
#include "unit-interface.h"

using namespace std;

namespace open_bracket {

void rank(const Request& request, Response* response) {
}

void start() {
	// TODO: load request.
	Request request;
	Response response;

	// TODO: write responses.
	rank(request, &response);
	//cout << "reponse = " << response.DebugString().c_str();
}

}  // namespace 

int main() {	
	cout << "Start service.\n";
	open_bracket::start();
	return 0;
}
