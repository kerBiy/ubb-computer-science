"""
Considerându-se o matrice cu n x m elemente întregi și o listă cu perechi formate din coordonatele a 2 căsuțe din matrice ((p,q) și (r,s)), să se calculeze suma elementelor din sub-matricile identificate de fieare pereche.

De ex, pt matricea
[[0, 2, 5, 4, 1],
[4, 8, 2, 3, 7],
[6, 3, 4, 6, 2],
[7, 3, 1, 8, 3],
[1, 5, 7, 9, 4]]
și lista de perechi ((1, 1) și (3, 3)), ((2, 2) și (4, 4)), suma elementelor din prima sub-matrice este 38, iar suma elementelor din a 2-a sub-matrice este 44.
"""


def sub_matrix_sum(matrix: list, coords: list) -> int:
    """
    Computes the sum of elements in a submatrix defined by given coordinates.
    :param matrix: A 2D list representing the matrix.
    :param coords: A tuple containing two coordinate pairs ((p, q), (r, s)).
    :return: The sum of elements in the submatrix.
    """
    s = 0

    for i in range(coords[0][0], coords[1][0] + 1):
        for j in range(coords[0][1], coords[1][1] + 1):
            s += matrix[i][j]

    return s


# Test cases
def test_sub_matrix_sum():
    matrix = [
        [0, 2, 5, 4, 1],
        [4, 8, 2, 3, 7],
        [6, 3, 4, 6, 2],
        [7, 3, 1, 8, 3],
        [1, 5, 7, 9, 4],
    ]
    assert sub_matrix_sum(matrix, [(1, 1), (3, 3)]) == 38
    assert sub_matrix_sum(matrix, [(2, 2), (4, 4)]) == 44
    assert sub_matrix_sum(matrix, [(0, 0), (4, 4)]) == sum(
        sum(row) for row in matrix
    )  # Entire matrix sum
    assert sub_matrix_sum(matrix, [(3, 2), (4, 4)]) == 32
    print("All tests passed!")


# Run tests
test_sub_matrix_sum()

"""
Time Complexity Analysis:
- In the worst case, it visits O(n * m) elements if the entire matrix is included in a query.
- Therefore, the time complexity is O(n * m).

Space Complexity Analysis:
- The space complexity is O(1).
"""
