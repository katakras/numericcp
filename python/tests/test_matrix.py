import test_setup
import example


def test_matrix_creation():
    m = example.MutableMatrix(2, 3)

    assert m.n_rows() == 2
    assert m.n_cols() == 3

    m[1, 1] = 2.0
    assert m[1, 1] == 2.0
