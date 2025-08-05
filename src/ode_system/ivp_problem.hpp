#pragma once

#include <memory>

#include "defs.hpp"
#include "ode_system/system.hpp"

namespace ode_system {

// Initial value problem representation, containing an underlying system of equations, an initial
// value x0 and the time interval [t0, tf] over which we want to compute the solution.
class ivp_problem {
 public:
  ivp_problem(std::shared_ptr<const system> sys, dvector x0, const double t0, const double tf);

  const auto& sys() const {
    return sys_;
  }
  const auto& x0() const {
    return x0_;
  }
  const double t0() const {
    return t0_;
  }
  const double tf() const {
    return tf_;
  }

 private:
  std::shared_ptr<const system> sys_;
  dvector x0_;
  double t0_;
  double tf_;
};
}  // namespace ode_system