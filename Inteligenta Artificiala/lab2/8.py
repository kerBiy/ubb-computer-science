# Să se genereze toate numerele (în reprezentare binară) cuprinse între 1 și n. De ex. dacă n = 4, numerele sunt: 1, 10, 11, 100.

from collections import deque


def generate_binary_numbers(n: int) -> list:
    """
    Generates all binary representations of numbers from 1 to n using a queue.
    :param n: The upper bound (inclusive).
    :return: A list of binary strings representing numbers from 1 to n.
    """
    if n < 1:
        raise ValueError("n must be at least 1")

    output = []
    queue = deque(["1"])  # Initialize queue with "1"

    for _ in range(n):
        num = queue.popleft()  # Get the front element
        output.append(num)  # Store the binary representation

        # Generate next binary numbers and add them to the queue
        queue.append(num + "0")
        queue.append(num + "1")

    return output


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
- The loop runs `n` times, so it has O(n) iterations.
- The queue operations (append and pop) are O(1), leading to an overall complexity of O(n).

Space Complexity Analysis:
- The queue and output list store up to O(n) elements, leading to O(n) space complexity.
"""
