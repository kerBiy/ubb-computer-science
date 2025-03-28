def generate_binary_numbers(n: int) -> list:
    """
    Generates all binary representations of numbers from 1 to n.
    :param n: The upper bound (inclusive).
    :return: A list of binary strings representing numbers from 1 to n.
    """
    if n < 1:
        raise ValueError("n must be at least 1")

    return [bin(i)[2:] for i in range(1, n + 1)]


# Test cases
def test_generate_binary_numbers():
    assert generate_binary_numbers(4) == ["1", "10", "11", "100"]
    assert generate_binary_numbers(1) == ["1"]
    assert generate_binary_numbers(2) == ["1", "10"]
    assert generate_binary_numbers(5) == ["1", "10", "11", "100", "101"]
    assert generate_binary_numbers(8) == [
        "1",
        "10",
        "11",
        "100",
        "101",
        "110",
        "111",
        "1000",
    ]
    print("All tests passed!")


# Run tests
test_generate_binary_numbers()

"""
Time Complexity Analysis:
- Iterating from 1 to n takes O(n) time.
- Converting each number to binary using bin() is O(log n).
- Overall complexity: O(n log n).

Space Complexity Analysis:
- The output list stores O(n) elements, leading to O(n) space complexity.
"""
