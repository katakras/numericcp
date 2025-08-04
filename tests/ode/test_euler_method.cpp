#include <catch2/catch_all.hpp>

#include "src/math/vector_operations.hpp"
#include "src/ode/euler_method.hpp"
#include "src/ode_system/system.hpp"

namespace {
using namespace vector_ops;

class dummy_system : public ode_system::system {
 public:
  dvector evaluate(const double t, const dvector& x) const override { return 0.1 * t + 0.5 * x; }
};
}  // namespace

TEST_CASE("Euler method (simple)", "[match]") {
  const auto& sys = std::make_shared<const dummy_system>();

  const double dt = 0.1;
  const auto& method = std::make_shared<const ode::euler_method>(dt);

  const dvector x = {-1.0, 1.0};

  const auto& [step_t, step_x] = method->evaluate_step(sys, 0.0, x);

  REQUIRE(step_t == (0.0 + dt));

  const auto& expected_x = x + dt * sys->evaluate(0.0, x);
  REQUIRE(step_x.size() == expected_x.size());
  REQUIRE(step_x[0u] == expected_x[0u]);
  REQUIRE(step_x[1u] == expected_x[1u]);
}