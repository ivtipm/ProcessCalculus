# этот модуль должен называться по шаблону: test_*.py
import pytest

def my_sum(l: list[float]) -> float:
    return sum( l )

# std тестируемая функция
def test_base():
    assert my_sum([]) == 0.0
    assert my_sum([10/3]) == pytest.approx(0.333333333)
    assert my_sum([1, 2, 3]) == 6


def test_negative():
        assert my_sum([-2, 2]) == 0.0


# pytest.approx — это объект со специальным сравнением, который переопределяет операцию ==, чтобы с допуском (погрешностью) сравнивать числа
