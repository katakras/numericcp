#pragma once

#include <stdexcept>

#include "defs.hpp"

namespace vector_ops {

inline dvector operator+(const dvector& vl, const dvector& vr) {
  if (vl.size() != vr.size()) throw std::invalid_argument("Vector sizes do not match.");

  dvector v(vl.size());
  for (std::size_t i = 0u; i < vl.size(); ++i) v[i] = vl[i] + vr[i];
  return v;
}

inline dvector operator+(const double scalar, const dvector& v) {
  dvector ret(v.size());
  for (std::size_t i = 0u; i < v.size(); ++i) ret[i] = scalar + v[i];
  return ret;
}

inline dvector operator+(const dvector& v, const double scalar) { return scalar + v; }

inline dvector operator*(const double scalar, const dvector& v) {
  dvector ret(v.size());
  for (std::size_t i = 0u; i < v.size(); ++i) ret[i] = scalar * v[i];
  return ret;
}

inline dvector operator*(const dvector& v, const double scalar) { return scalar * v; }

}  // namespace vector_ops