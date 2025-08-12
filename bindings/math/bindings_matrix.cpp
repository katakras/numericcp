#include "bindings/math/bindings_matrix.hpp"

#include <nanobind/nanobind.h>

#include <cstdio>

#include "src/math/matrix.hpp"

namespace nb = nanobind;

void bind_matrix(nanobind::module_& m) {
  nb::class_<math::Matrix>(m, "Matrix")
      .def(nb::init<std::size_t, std::size_t>())
      .def("n_rows", &math::Matrix::n_rows)
      .def("n_cols", &math::Matrix::n_cols)
      .def("__getitem__",
           [](const math::Matrix& self, nb::tuple ij) {
             if (ij.size() != 2u)
               throw std::runtime_error("Wrong number of indices used");
             const size_t row = nb::cast<std::size_t>(ij[0]);
             const size_t col = nb::cast<std::size_t>(ij[1]);
             return self(row, col);
           })
      .def("__setitem__", [](math::Matrix& self, nb::tuple ij, double value) {
        if (ij.size() != 2u)
          throw std::runtime_error("Wrong number of indices used");
        const size_t row = nb::cast<std::size_t>(ij[0]);
        const size_t col = nb::cast<std::size_t>(ij[1]);
        self(row, col) = value;
      });
}