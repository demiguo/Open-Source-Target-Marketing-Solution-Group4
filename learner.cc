#include <iostream>
#include <string>
#include <vector>
#include "model-interface.h"
#include "feature-interface.h"
#include "utils.h"

using namespace std;

namespace open_bracket {

void train_model(const std::vector<Feature>& features, Model* model) {
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
