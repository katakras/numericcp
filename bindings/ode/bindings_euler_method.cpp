#include "bindings/ode/bindings_euler_method.hpp"

#include <nanobind/nanobind.h>
#include <nanobind/stl/shared_ptr.h>
#include <nanobind/stl/vector.h>

#include "src/ode/euler_method.hpp"

namespace nb = nanobind;

void bind_euler_method(nanobind::module_& m) {
  nb::class_<ode::euler_method>(m, "euler_method").def(nb::init<double>());
}