#include "bindings/ode_system/bindings_ivp_problem.hpp"

#include <nanobind/nanobind.h>
#include <nanobind/stl/shared_ptr.h>
#include <nanobind/stl/vector.h>

#include "src/defs.hpp"
#include "src/ode_system/ivp_problem.hpp"
#include "src/ode_system/system.hpp"

namespace nb = nanobind;

void bind_ivp_problem(nanobind::module_& m) {
  nb::class_<ode_system::ivp_problem>(m, "ivp_problem")
      .def(nb::init<std::shared_ptr<const ode_system::system>, dvector, double, double>());
}