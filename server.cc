#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
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

void rank(const Request& request, const Model& model, Response* response) {
	Unit unit;
	unit.display_name = "downtown";
	response->units.push_back(unit);
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

	Request request;
#ifdef ENABLE_CGI
	Cgicc formData;
	// TODO: parse request from HTML.
#endif

	Response response;
	rank(request, model, &response);
	generate_html(response);
}

}  // namespace 

int main() {
//    FILE* f = fopen("test", "a");
//    fprintf(f, "yes\n");
//    fclose(f);
	open_bracket::start();
	return 0;
}
