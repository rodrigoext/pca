#include <iostream>
#include "pca.h"
#include <Eigen/Dense>

int main() {
	PCA pca;
	Eigen::MatrixXf data(2, 2);
	data << 2, 0,
			0, 1;
	Eigen::VectorXf r = pca.Compute(data);
	std::cout << "Result: " << std::endl << r.transpose() << std::endl;
	return 0;
}