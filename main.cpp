#include <iostream>
#include "pca.h"
#include <Eigen/Dense>

int main() {
	std::cout << "Init PCA..." << std::endl;
	PCA pca;
	Eigen::MatrixXf data(2, 2);
	data << 1, 0,
			0, 1;
	Eigen::VectorXf r = pca.Compute(data);
	std::cout << "Result: " << std::endl << r << std::endl;
	return 0;
}