#include "math/matrix.hpp"

#include <stdexcept>

namespace math {

Matrix::Matrix(const std::size_t n_rows, const std::size_t n_cols)
    : n_rows_(n_rows),
      n_cols_(n_cols),
      storage_(new double[n_rows * n_cols]()) {}

Matrix::Matrix(Matrix&& m) : n_rows_(m.n_rows()), n_cols_(m.n_cols()), storage_(m.storage_) {
  m.storage_ = new double[0u]();
}

Matrix::~Matrix() {
  delete[] storage_;
}

double& Matrix::operator()(const std::size_t row, const std::size_t col) {
  if (row >= n_rows_ || col >= n_cols_)
    throw std::out_of_range("Matrix index out of range.");
  return storage_[row * n_cols_ + col];
}
double Matrix::operator()(const std::size_t row, const std::size_t col) const {
  if (row >= n_rows_ || col >= n_cols_)
    throw std::out_of_range("Matrix index out of range.");
  return storage_[row * n_cols_ + col];
}

}  // namespace math