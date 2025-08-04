#pragma once

#include "defs.hpp"
#include "ode_system/system.hpp"

namespace ode_system {

// Linear system of the form dx/dt = alpha + beta * x
class linear_system : public system {
 public:
  linear_system(const double alpha, const double beta);
  dvector evaluate(const double t, const dvector& x) const override;

 private:
  double alpha_;
  double beta_;
};

}  // namespace ode_system