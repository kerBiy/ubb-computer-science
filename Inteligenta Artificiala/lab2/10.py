"""
Considerându-se o matrice cu n x m elemente binare (0 sau 1) sortate crescător pe linii, să se identifice indexul liniei care conține cele mai multe elemente de 1.

De ex. în matricea
[[0,0,0,1,1],
[0,1,1,1,1],
[0,0,1,1,1]]
a doua linie conține cele mai multe elemente 1.
"""


def row_with_most_ones(matrix: list) -> int:
    """
    Finds the index of the row with the most 1s in a binary matrix sorted row-wise.
    :param matrix: A 2D list with binary values (0s and 1s) sorted in ascending order per row.
    :return: The index of the row containing the most 1s.
    """
    max_ones = -1
    max_row_index = -1

    for i, row in enumerate(matrix):
        ones_count = len(row) - row.index(1) if 1 in row else 0
        if ones_count > max_ones:
            max_ones = ones_count
            max_row_index = i

    return max_row_index


# Test cases
def test_row_with_most_ones():
    matrix = [[0, 0, 0, 1, 1], [0, 1, 1, 1, 1], [0, 0, 1, 1, 1]]
    assert row_with_most_ones(matrix) == 1

    matrix2 = [[0, 0, 0, 0], [0, 0, 1, 1], [0, 1, 1, 1]]
    assert row_with_most_ones(matrix2) == 2

    matrix3 = [[1, 1, 1, 1], [0, 1, 1, 1], [0, 0, 1, 1]]
    assert row_with_most_ones(matrix3) == 0

    matrix4 = [[0, 0, 0, 0], [0, 0, 0, 0], [0, 0, 0, 1]]
    assert row_with_most_ones(matrix4) == 2

    print("All tests passed!")


# Run tests
test_row_with_most_ones()

"""
Time Complexity Analysis:
- Finding the first occurrence of 1 in a row takes O(m) in the worst case.
- Iterating through all rows makes it O(n * m) in total.
- If optimized with binary search, it can be reduced to O(n log m).

Space Complexity Analysis:
- The function uses only a few additional variables, so the space complexity is O(1).
"""
