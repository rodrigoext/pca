#include "pca.h"
#include <iostream>

PCA::PCA()
{

}

Eigen::VectorXf PCA::Compute(const Eigen::MatrixXf &data)
{
	// Compute the d-dimensional mean vector
	Eigen::VectorXf means = data.colwise().mean();

	// Subtract mean image from the data set to get mean centered data vector
	Eigen::MatrixXf U = data.rowwise() - means.transpose();

	// Covariance matrix from the mean centered data matrix
	Eigen::MatrixXf covariance = (U.transpose() * U) / (float)(data.rows());

	// Calculate the eigenvalues and eigenvectors for the covariance matrix
	Eigen::EigenSolver<Eigen::MatrixXf> solver(covariance);
	Eigen::MatrixXf eigen_vectors = solver.eigenvectors().real();
	Eigen::VectorXf eigen_values = solver.eigenvalues().real();

	eigen_vectors.normalize();

	std::sort(eigen_values.derived().data(), eigen_values.derived().data() + eigen_values.derived().size());
	short index = eigen_values.size() - 1;
	Eigen::VectorXf feature_vector = eigen_vectors.row(index);

	return feature_vector;
}

PCA::~PCA()
{

}