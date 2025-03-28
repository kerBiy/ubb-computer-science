"""
Să se determine distanța Euclideană între două locații identificate prin perechi de numere. De ex. distanța între (1,5) și (4,1) este 5.0
"""

from math import sqrt, isclose

def euclidean_distance(point1: tuple, point2: tuple) -> float:
    """
    Computes the Euclidean distance between two points.
    :param point1: Tuple representing the first point (x1, y1).
    :param point2: Tuple representing the second point (x2, y2).
    :return: The Euclidean distance between the two points.
    """
    return sqrt((point2[0] - point1[0]) ** 2 + (point2[1] - point1[1]) ** 2)


def test_euclidean_distance():
    assert isclose(euclidean_distance((1, 5), (4, 1)), 5.0, rel_tol=1e-9)
    assert isclose(euclidean_distance((0, 0), (3, 4)), 5.0, rel_tol=1e-9)
    assert isclose(euclidean_distance((2, 3), (2, 3)), 0.0, rel_tol=1e-9)
    assert isclose(euclidean_distance((-1, -1), (2, 3)), 5.0, rel_tol=1e-9)
    print("All tests passed for euclidean_distance!")


# Run tests
test_euclidean_distance()

"""
Time Complexity Analysis:
   - Computes the square difference and square root in constant time O(1).
   - Space Complexity: O(1) as it uses only a few variables.
"""
