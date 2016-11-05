#include <iostream>
#include "server.pb.h"

using namespace std;

namespace open_bracket {

void rank(const Request& request, Response* response) {
	auto* unit = response->add_unit();
	unit->set_display_name("downtown");
	unit->set_id(0);
}

void start() {
	// TODO: load request.
	Request request;
	Response response;

	// TODO: write responses.
	rank(request, &response);
	cout << "reponse = " << response.DebugString().c_str();
}

}  // namespace 

int main() {	
	cout << "Start service.\n";
	open_bracket::start();
	return 0;
}
