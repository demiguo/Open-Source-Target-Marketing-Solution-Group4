#include <iostream>
#include <string>
#include <vector>
#include <cmath>

#include "../interface/model-interface.h"
#include "../interface/feature-interface.h"
#include "../utils/utils.h"
#include "linear_regression.h"

using namespace std;

namespace open_bracket {

namespace rule_based {

void train(const std::vector<Feature>& features, Model* model) {
	// TODO: Implement linear regression.
	model->model_name = "Linear_regression";
	auto* parameters = &model->parameters;
	parameters->clear();
	parameters->resize(NUM_FEATURES, 0.0);
	(*parameters)[POPULATION] = 1.0;
}

}

namespace linear_regression {

vector<vector<double>> create_array(int n, int m) {
	vector<vector<double>> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = vector<double>(m, 0);
	}
	return a;
}

void print(const vector<double>& a) {
	for (double x : a) printf("%.2lf ", x);
	printf("\n");	
}

void print(const vector<vector<double>>& a) {
	for (const auto& row : a) {
		print(row);
	}
}

void train(const std::vector<Feature>& features, Model* model) {
	const int num_features = NUM_FEATURES;
	const int num_labels = features.size();
	vector<vector<double>> a = create_array(num_features, num_features);
	for (const auto& feature : features) {
		const auto& x = feature.features;
		if (x.size() != NUM_FEATURES) continue;
		for (int i = 0; i < num_features; ++i) {
			for (int j = 0; j < num_features; ++j) {
				a[i][j] += x[i] * x[j];
			}
		}
	}
	vector<double> b(num_features, 0.0);
	for (const auto& feature : features) {
		const auto& x = feature.features;
		if (x.size() != NUM_FEATURES) continue;
		const double y = feature.label;
		for (int i = 0; i < num_features; ++i) {
			b[i] += x[i] * y;
		}
	}

	// gauss.
	const double eps = 1e-3;
	vector<int> eliminated_variable(num_features, -1);
	for (int i = 0; i < num_features; ++i) {
		int key = 0;
		for (int j = 0; j < num_features; ++j) {
			if (fabs(a[i][j]) > fabs(a[i][key]))
				key = j;
		}
		if (fabs(a[i][key]) <= eps) continue;
		eliminated_variable[i] = key;
		for (int k = i + 1; k < num_features; ++k) {
			double rate = a[k][key] / a[i][key];
			for (int j = 0; j < num_features; ++j)
				a[k][j] -= rate * a[i][j];
			b[k] -= rate * b[i];
		}
	}

	model->model_name = "Linear_regression";
	auto* parameters = &model->parameters;
	parameters->clear();
	parameters->resize(NUM_FEATURES, 0.0);
	for (int i = num_features - 1; i >= 0; --i) {
		int key = eliminated_variable[i];
		if (key < 0) continue;
		double x = b[i];
		for (int j = 0; j < num_features; ++j) {
			if (j != key) {
				x -= a[i][j] * (*parameters)[j];
			}
		}
		x /= a[i][key];
		(*parameters)[i] = x;
	}
}

}

void train_model(const std::vector<Feature>& features, Model* model) {
	//rule_based::train(features, model);
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
