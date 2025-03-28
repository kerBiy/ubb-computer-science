# Să se determine produsul scalar a doi vectori rari care conțin numere reale. Un vector este rar atunci când conține multe elemente nule. Vectorii pot avea oricâte dimensiuni. De ex. produsul scalar a 2 vectori unisimensionali [1,0,2,0,3] și [1,2,0,3,1] este 4.

def sparse_dot_product(vec1: list, vec2: list) -> float:
    """
    Computes the dot product of two sparse vectors.
    :param vec1: First sparse vector as a list of floats.
    :param vec2: Second sparse vector as a list of floats.
    :return: The dot product of the two vectors.
    """
    if len(vec1) != len(vec2):
        raise ValueError("Vectors must have the same dimensions.")

    return sum(x * y for x, y in zip(vec1, vec2) if x != 0 and y != 0)


def test_sparse_dot_product():
    assert sparse_dot_product([1, 0, 2, 0, 3], [1, 2, 0, 3, 1]) == 4
    assert sparse_dot_product([0, 0, 0, 0], [1, 2, 3, 4]) == 0
    assert sparse_dot_product([1.5, 0, 2.5], [0, 3, 1]) == 2.5
    assert sparse_dot_product([0, 1, 0, 0, 2], [1, 0, 3, 0, 1]) == 2
    print("All tests passed!")


# Run tests
test_sparse_dot_product()

"""
Time Complexity Analysis:
- The function iterates over the vectors once, performing O(n) operations, where n is the length of the vectors.
- The filtering operation ensures that we skip multiplications with zero, optimizing for sparsity.
- Overall time complexity: O(n).

Space Complexity Analysis:
- The function uses only a few extra variables, making the space complexity O(1).
"""
