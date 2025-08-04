#include "ode/ode_solver.hpp"

namespace ode {

namespace {
// Visitor for different ODE methods, in case they require some extra logic that goes beyond just
// evaluating the next step and requires to know something from the integration loop.
struct method_visitor {
  method_visitor(const std::shared_ptr<const ode_system::system>& s,
                 const double t,
                 const dvector& x)
      : s_(s),
        t_(t),
        x_(x) {};

  template <typename T>
  std::pair<double, dvector> operator()(const std::shared_ptr<const T>& m) const {
    return m->evaluate_step(s_, t_, x_);
  }

 private:
  const std::shared_ptr<const ode_system::system>& s_;
  const double t_;
  const dvector& x_;
};

math::Matrix transform_result_into_matrix(const std::vector<dvector>& results) {
  const std::size_t n_rows = results.front().size();
  const std::size_t n_cols = results.size();

  math::Matrix m(n_rows, n_cols);
  for (std::size_t i_row = 0u; i_row < n_rows; ++i_row) {
    for (std::size_t i_col = 0u; i_col < n_cols; ++i_col) {
      m(i_row, i_col) = results[i_col][i_row];
    }
  }
  return m;
}

}  // namespace

math::Matrix solve_ivp(const std::shared_ptr<const ode_system::ivp_problem>& problem,
                       const method& method) {
  auto t = problem->t0();

  const auto& tf = problem->tf();
  const auto& system = problem->sys();

  std::vector<dvector> x_results(1u);
  x_results[0u] = problem->x0();

  while (t < tf) {
    const auto& [step_t, step_x] = std::visit(method_visitor(system, t, x_results.back()), method);

    t = step_t;
    x_results.emplace_back(std::move(step_x));
  }

  return transform_result_into_matrix(x_results);
}
}  // namespace ode