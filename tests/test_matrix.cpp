#include <catch2/catch_all.hpp>

#include "src/math/matrix.hpp"

TEST_CASE("Matrix basic operations", "[matrix]") {
  math::Matrix m(2u, 3u);
  REQUIRE(m.n_rows() == 2u);
  REQUIRE(m.n_cols() == 3u);
}