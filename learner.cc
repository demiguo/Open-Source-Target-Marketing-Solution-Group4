#include <iostream>
#include <string>
#include <vector>
#include "model-interface.h"
#include "feature-interface.h"

using namespace std;

namespace open_bracket {

string model_name = "";

void train_model(const std::vector<Feature>& features, Model* model) {
}

void learner() {
	std::vector<Feature> features;
	// TODO: load features from file.

	Model model;
	train_model(features, &model);

	// TODO: write model to file.
}

}  // namespace 

int main() {
	open_bracket::learner();
	return 0;
}
