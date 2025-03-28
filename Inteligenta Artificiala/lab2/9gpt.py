def compute_submatrix_sums(matrix: list, queries: list) -> list:
    """
    Computes the sum of elements in submatrices defined by pairs of coordinates.
    :param matrix: A 2D list representing the matrix.
    :param queries: A list of tuples, where each tuple contains two coordinate pairs ((p, q), (r, s)).
    :return: A list of sums corresponding to each submatrix.
    """

    def submatrix_sum(p, q, r, s):
        return sum(matrix[i][j] for i in range(p, r + 1) for j in range(q, s + 1))

    return [submatrix_sum(p, q, r, s) for (p, q), (r, s) in queries]


# Test cases
def test_compute_submatrix_sums():
    matrix = [
        [0, 2, 5, 4, 1],
        [4, 8, 2, 3, 7],
        [6, 3, 4, 6, 2],
        [7, 3, 1, 8, 3],
        [1, 5, 7, 9, 4],
    ]
    queries = [((1, 1), (3, 3)), ((2, 2), (4, 4))]
    expected_results = [38, 44]
    assert compute_submatrix_sums(matrix, queries) == expected_results
    print("All tests passed!")


# Run tests
test_compute_submatrix_sums()

"""
Time Complexity Analysis:
- The function iterates over the submatrix defined by each query.
- Given that each query may cover up to O(n*m) elements in the worst case, the complexity per query is O(n*m).
- If `q` queries are performed, the overall complexity is O(q * n * m).

Space Complexity Analysis:
- The function uses only a small amount of additional space for storing results, leading to O(q) space complexity.
"""
