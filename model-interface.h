#ifndef MODEL_INTERFACE_H
#define MODEL_INTERFACE_H

#include <sstream>
#include <string>

struct Model {
	std::string model_name;
	std::vector<double> parameters;

	std::string serialize_to_string() const { 
		std::ostringstream sout;
		sout << model_name << " " << parameters.size();
		for (double p : parameters) {
			sout << " " << p;
		}
		return "";
	}
	void parse_from_string(const std::string& s) {
		std::istringstream sin(s);
		int num_parameters = 0;
		sin >> model_name >> num_parameters;
		parameters.clear();
		parameters.reserve(num_parameters);
		for (int i = 0; i < num_parameters; ++i) {
			double p;
			sin >> p;
			parameters.push_back(p);
		}
	}
};

#endif  // MODEL_INTERFACE_H
