#include <iostream>
#include <vector>
#include "model-interface.h"
#include "server-interface.h"
#include "unit-interface.h"

using namespace std;

namespace open_bracket {

void rank(const Request& request, const Model& model, Response* response) {
	Unit unit;
	unit.display_name = "downtown";
	response->units.push_back(unit);
}

void start() {
	// TODO: load model.
	Model model;

	// TODO: load request.
	Request request;
	Response response;

	// TODO: write responses.
	rank(request, model, &response);
	//cout << "reponse = " << response.DebugString().c_str();
}

}  // namespace 

int main() {	
	cout << "Start service.\n";
	open_bracket::start();
	return 0;
}
