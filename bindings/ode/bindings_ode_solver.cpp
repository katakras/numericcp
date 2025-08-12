#include "bindings/ode/bindings_ode_solver.hpp"

#include <nanobind/nanobind.h>
#include <nanobind/stl/shared_ptr.h>
#include <nanobind/stl/variant.h>

#include "src/ode/ode_solver.hpp"

namespace nb = nanobind;

void bind_ode_solver(nb::module_& m) {
  m.def("solve_ivp", &ode::solve_ivp);
};