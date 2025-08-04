#pragma once

#include <memory>

#include "defs.hpp"
#include "ode_system/system.hpp"

namespace math {
class Matrix;
}

namespace ode {

// Euler method, where to integrate an approximation is taken such that x(t+dt) = x(t) + dt *
// dx/dt(t)
class euler_method {
 public:
  euler_method(const double dt);

  std::pair<double, dvector> evaluate_step(const std::shared_ptr<const ode_system::system> system,
                                           const double t,
                                           const dvector& x) const;

 private:
  double dt_;
};
}  // namespace ode