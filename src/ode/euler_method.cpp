#include "ode/euler_method.hpp"

#include "math/matrix.hpp"
#include "math/vector_operations.hpp"

using namespace vector_ops;

namespace ode {

euler_method::euler_method(const double dt) : dt_(dt) {}

std::pair<double, dvector> euler_method::evaluate_step(
    const std::shared_ptr<const ode_system::system> system,
    const double t,
    const dvector& x) const {
  return {t + dt_, x + dt_ * system->evaluate(t, x)};
}
}  // namespace ode