#pragma once

#include "defs.hpp"

namespace ode_system {

// Base class for systems of equations.
class system {
 public:
  virtual dvector evaluate(const double t, const dvector& x) const = 0;
};
}  // namespace ode_system