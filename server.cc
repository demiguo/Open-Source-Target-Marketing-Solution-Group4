#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_set>

#include "feature-interface.h"
#include "model-interface.h"
#include "server-interface.h"
#include "unit-interface.h"
#include "utils.h"

#define ENABLE_CGI
#ifdef ENABLE_CGI
#include <cgicc/CgiDefs.h> 
#include <cgicc/Cgicc.h> 
#include <cgicc/HTTPHTMLHeader.h> 
#include <cgicc/HTMLClasses.h> 
#endif

using namespace std;

namespace open_bracket {
namespace {
const std::string default_location = "100050517021070";
const std::string rest1 = "100030019022004";
const std::string rest2 = "100030014001012";
}

namespace linear_regression {

double predict(const Unit& unit, const Model& model) {
	Feature feature;
	vector<double> hidden_features(NUM_HIDDEN_FEATURES, 0.0);
	feature.update(unit, hidden_features);
	double sum = 0;
	for (int i = 0; i < NUM_FEATURES; ++i) {
		sum += model.parameters[i] * feature.features[i];
	}
	return sum;
}

}

bool filter_by_svd_similarity(int64_t location, vector<Unit>* units) {
	FILE *f = fopen("data/svd_similarity.dat", "r");
	if (f == nullptr) return false;
	unordered_set<int64_t> selected;
	while (fgets(line, 1 << 20, f) != nullptr) {
		istringstream sin(line);
		int64_t key;
		sin >> key;
		if (key != location) continue;
		for (; sin >> key; ) selected.insert(key);
	}
	fclose(f);
	int num_selected = 0;
	for (const auto& unit : *units) {
		if (selected.count(unit.id)) ++num_selected;
	}
	if (num_selected < 20) {
		return false;
	}
	vector<Unit> filtered_units;
	for (const auto& unit : *units) {
		if (selected.count(unit.id)) filtered_units.push_back(unit);
	}
	units->swap(filtered_units);
	return true;
}

void rank(const Request& request, const Model& model, const SQueryIndex& index, Response* response) {
	// Extract candidates.
	std::string location = request.query_location;
	if (location.empty()) {
		location = default_location;
	}
	vector<std::string> queries = generate_location_s_query(location);
	int64_t opt_s_query_count = 0;
	std::string opt_s_query;
	int64_t expected_count = request.num_results * 3;
	for (const auto& query : queries) {
		if (!index.num_contents.count(query)) {
			continue;
		}
		const int64_t count = index.num_contents.at(query);
		if ((count >= expected_count && (opt_s_query_count < expected_count || count < opt_s_query_count)) ||
				(count < expected_count && opt_s_query_count < expected_count && count > opt_s_query_count)) {
			opt_s_query = query;
			opt_s_query_count = count;
		}
	}
	if (opt_s_query.empty()) {
		return;
	}

	vector<Unit> units;
	load_from_file(unit_filename(opt_s_query), &units);

	filter_by_svd_similarity(stol(location), &units);

	// Ranking
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

std::string description;
void generate_html(const Response& response) {
	string ret = "Content-type:text/html\r\n\r\n"; 
    ret += "<html>\n";
	ret += "  <head>\n";
	ret += "    <title>Results</title>\n";
	ret += "<meta charset=\"utf-8\">\n\
<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n\
<link href=\"http://apps.bdimg.com/libs/bootstrap/3.3.0/css/bootstrap.min.css\" rel=\"stylesheet\">\n \
<link href=\"http://apps.bdimg.com/libs/bootstrap/3.3.0/css/bootstrap-theme.min.css\" rel=\"stylesheet\">\n \
<script src=\"http://apps.bdimg.com/libs/jquery/2.0.0/jquery.min.js\"></script>\n\
<script src=\"http://apps.bdimg.com/libs/bootstrap/3.3.0/js/bootstrap.min.js\"></script>\n";
	ret += "  </head>\n";
	ret += "  <body>\n";
	int id = 0;
	ret += "<div class=\"main\" style=\"background:transparent\">\n";
	ret += "<div class=\"btn-group\" role=\"group\">\n";
	for (const auto& unit : response.units) {
		id ++;
		const string text = "Rank" + to_string(id);
		const string link = "https://www.google.com/maps/@" + to_string(unit.lat)+ "," + to_string(unit.lng) + ",15z";
		ret += "<a href=\"" + link + "\" target=\"_blank\" class=\"btn btn-warning btn-lg btn-block\" role=\"button\">" + text + "</a>";
	}
	ret += "</div></div>\n";
//    ret += "<p>" + description + "</p>\n";
	ret += "  </body>\n";
	ret += "</html>\n";
	cout << ret << endl;
}

void parse_request(const std::string& description, Request* request) {
	// Not implemented yet.
	// TODO: use NLP to parse the meaning of the description.

	// Followings are hacky code for demos.
	if (description.find("Harry's Seafood") != -1) {
		request->query_location = rest1;
	} else if (description.find("Desserts") != -1) {
		request->query_location = rest2;
	}
	//FILE *f = fopen("test.log", "w");
	//fprintf(f, "description = %s\n", description.c_str());
	//fprintf(f, "request.query_location = %s\n", request->query_location.c_str());
	//fclose(f);
}

void start() {
	Model model;
	load_from_file(model_file, &model);

	SQueryIndex index;
	load_from_file(unit_squery_index_filename, &index);

	Request request;
#ifdef ENABLE_CGI
    cgicc::Cgicc formData;
	// TODO: parse request from HTML.
    description = formData.getElement("input_describe")->getValue();
    parse_request(description, &request);
	// TODO: parse current location from HTML.
#endif

    //formData
	Response response;
	rank(request, model, index, &response);
	generate_html(response);
}

}  // namespace 

int main() {
	open_bracket::start();
	return 0;
}
