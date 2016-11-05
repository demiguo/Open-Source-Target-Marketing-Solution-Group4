#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "feature-interface.h"
#include "model-interface.h"
#include "server-interface.h"
#include "unit-interface.h"
#include "utils.h"
//#ifdef ENABLE_CGI

#ifdef ENABLE_CGI
#include <cgicc/CgiDefs.h> 
#include <cgicc/Cgicc.h> 
#include <cgicc/HTTPHTMLHeader.h> 
#include <cgicc/HTMLClasses.h> 
#endif

using namespace std;

namespace open_bracket {

namespace linear_regression {

double predict(const Unit& unit, const Model& model) {
	Feature feature;
	feature.update(unit);
	double sum = 0;
	for (int i = 0; i < NUM_FEATURES; ++i) {
		sum += model.parameters[i] * feature.features[i];
	}
	return sum;
}

}

void rank(const Request& request, const Model& model, const vector<Unit>& units, Response* response) {
	vector<pair<double, const Unit*>> units_sorted_by_score;
	for (const auto& unit : units) {
		units_sorted_by_score.emplace_back(linear_regression::predict(unit, model), &unit);
	}
	sort(units_sorted_by_score.rbegin(), units_sorted_by_score.rend());
	if (request.num_results > 0 && request.num_results < units_sorted_by_score.size()) {
		units_sorted_by_score.resize(request.num_results);
	}
	for (const auto& unit : units_sorted_by_score) {
		response->units.push_back(*unit.second);
	}
}

void generate_html(const Response& response) {
	string ret = "Content-type:text/html\r\n\r\n"; 
    ret += "<html>\n";
	ret += "  <head>\n";
	ret += "    <title>Results</title>\n";
	ret += "  </head>\n";
	ret += "  <body>\n";
	for (const auto& unit : response.units) {
		ret += "    <p>";
		ret += unit.display_name;
		ret += "</p>\n";
	}
	ret += "  </body>\n";
	ret += "</html>\n";
	cout << ret << endl;
}

void start() {
	Model model;
	load_from_file(model_file, &model);

	vector<Unit> units;
	load_from_file(unit_filename, &units);

	Request request;
#ifdef ENABLE_CGI
	Cgicc formData;
	// TODO: parse request from HTML.
#endif

	Response response;
	rank(request, model, units, &response);
	generate_html(response);
}

}  // namespace 

int main() {
	open_bracket::start();
	return 0;
}
