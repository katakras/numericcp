#include "ode_system/ivp_problem.hpp"

namespace ode_system {

ivp_problem::ivp_problem(std::shared_ptr<const system> sys,
                         dvector x0,
                         const double t0,
                         const double tf)
    : sys_(std::move(sys)),
      x0_(std::move(x0)),
      t0_(t0),
      tf_(tf) {}
}  // namespace ode_system