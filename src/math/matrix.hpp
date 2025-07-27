#pragma once

#include <cstddef>

namespace math {

class Matrix {
 public:
  Matrix(const std::size_t n_rows, const std::size_t n_cols);

  ~Matrix();

  double& operator()(const std::size_t row, const std::size_t col);
  double operator()(const std::size_t row, const std::size_t col) const;

  auto n_rows() const { return n_rows_; }
  auto n_cols() const { return n_cols_; }

 private:
  std::size_t n_rows_;
  std::size_t n_cols_;
  double* storage_;
};

}  // namespace math