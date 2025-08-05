#include <math.h>

#include <catch2/catch_all.hpp>

#include "src/ode/euler_method.hpp"
#include "src/ode/ode_solver.hpp"
#include "src/ode_system/ivp_problem.hpp"
#include "src/ode_system/linear_system.hpp"

TEST_CASE("Linear ODE system evaluation", "[ode_system]") {
  const double alpha = 0.1;
  const double beta = 0.2;
  const ode_system::linear_system s(alpha, beta);

  const dvector x = {1.0, 2.0};

  const auto& dx = s.evaluate(0.0, x);
  REQUIRE(dx.size() == 2u);
  REQUIRE(dx[0u] == alpha + beta * x[0u]);
  REQUIRE(dx[1u] == alpha + beta * x[1u]);
}

TEST_CASE("Simple exponential solution", "[ode_system]") {
  const double dt = 0.05;
  const auto& sys = std::make_shared<const ode_system::linear_system>(0.0, 1.0);
  const dvector x = {0.0, 1.0};
  const auto& problem = std::make_shared<const ode_system::ivp_problem>(sys, x, 0.0, 1.0);

  const auto& method = std::make_shared<const ode::euler_method>(dt);

  const auto& result = solve_ivp(problem, method);

  const std::size_t expected_n_steps = static_cast<std::size_t>(1.0 / dt);
  REQUIRE(result.n_rows() == 2u);
  REQUIRE(result.n_cols() == (expected_n_steps + 1u));

  // exp(0) should be 0
  REQUIRE(result(0u, 20u) == 0.0);

  // manually working out the result of using the Euler method
  double expected_exp_1 = 1.0;
  for (std::size_t i = 0u; i < expected_n_steps; ++i) expected_exp_1 += dt * expected_exp_1;
  REQUIRE(std::fabs(result(1u, 20u) - expected_exp_1) < 1e-10);
}