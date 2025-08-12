#include "bindings/ode_system/bindings_system.hpp"

#include <nanobind/nanobind.h>

#include "src/ode_system/system.hpp"

namespace nb = nanobind;

void bind_system(nanobind::module_& m) {
  nb::class_<ode_system::system>(m, "system");
}