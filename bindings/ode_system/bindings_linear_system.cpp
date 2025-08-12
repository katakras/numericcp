#include "bindings/ode_system/bindings_linear_system.hpp"

#include <nanobind/nanobind.h>

#include "src/ode_system/linear_system.hpp"

namespace nb = nanobind;

void bind_linear_system(nanobind::module_& m) {
  nb::class_<ode_system::linear_system, ode_system::system>(m, "linear_system")
      .def(nb::init<double, double>());
}