#include "ode_system/linear_system.hpp"

#include "math/vector_operations.hpp"

using namespace vector_ops;

namespace ode_system {

linear_system::linear_system(const double alpha, const double beta) : alpha_(alpha), beta_(beta) {}

dvector linear_system::evaluate(const double t, const dvector& x) const {
  return alpha_ + beta_ * x;
}
}  // namespace ode_system