#include <nanobind/nanobind.h>

#include "bindings/math/bindings_matrix.hpp"
#include "bindings/ode/bindings_euler_method.hpp"
#include "bindings/ode/bindings_ode_solver.hpp"
#include "bindings/ode_system/bindings_ivp_problem.hpp"
#include "bindings/ode_system/bindings_linear_system.hpp"
#include "bindings/ode_system/bindings_system.hpp"

NB_MODULE(example, m) {
  bind_matrix(m);
  bind_euler_method(m);
  bind_ode_solver(m);
  bind_system(m);
  bind_ivp_problem(m);
  bind_linear_system(m);
}
