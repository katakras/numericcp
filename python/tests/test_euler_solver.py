import test_setup
import example


def test_euler_method():
    ls = example.linear_system(0.0, 1.0)
    ivp = example.ivp_problem(ls, [0.0, 1.0], 0.0, 1.0)

    solver = example.euler_method(0.05)

    result = example.solve_ivp(ivp, solver)
    assert result.n_cols() == 21
    assert result.n_rows() == 2

    assert result[0, 0] == 0.0
    assert result[1, 0] == 1.0

    assert result[0, 20] == 0.0
    assert abs(result[1, 20] - 2.653297705144) < 1e-8
