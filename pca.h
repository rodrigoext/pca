#pragma once
#include <Eigen/Dense>

class PCA
{
public:
	PCA();
	Eigen::VectorXf Compute(const Eigen::MatrixXf &data);
	~PCA();
	
};