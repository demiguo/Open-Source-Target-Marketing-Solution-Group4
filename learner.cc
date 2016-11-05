#include <iostream>
#include <string>
#include <vector>
#include "model-interface.h"
#include "feature-interface.h"
#include "utils.h"

using namespace std;

namespace open_bracket {

namespace linear_regression {

void train(const std::vector<Feature>& features, Model* model) {
	// TODO: Implement linear regression.
	model->model_name = "Linear_regression";
	auto* parameters = &model->parameters;
	parameters->clear();
	parameters->resize(NUM_FEATURES, 0.0);
	(*parameters)[POPULATION] = 1.0;
}

}

void train_model(const std::vector<Feature>& features, Model* model) {
	linear_regression::train(features, model);
}

void learner() {
	std::vector<Feature> features;
	load_from_file(feature_filename, &features);

	Model model;
	train_model(features, &model);
	write_to_file(model_file, model);
}

}  // namespace 

int main() {
	open_bracket::learner();
	return 0;
}
