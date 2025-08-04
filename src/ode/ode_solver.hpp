#pragma once

#include <variant>

#include "math/matrix.hpp"
#include "ode/euler_method.hpp"
#include "ode_system/ivp_problem.hpp"

namespace ode {

using method = std::variant<std::shared_ptr<const euler_method>>;

// Solve an initial value problem using the given method.
math::Matrix solve_ivp(const std::shared_ptr<const ode_system::ivp_problem>& problem,
                       const method& method);
}  // namespace ode