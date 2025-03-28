from collections import Counter


def majority_element(nums: list) -> int:
    """
    Finds the majority element in a list (element appearing more than n/2 times).
    :param nums: List of integers containing a majority element.
    :return: The majority element.
    """
    counts = Counter(nums)
    n = len(nums)

    for num, count in counts.items():
        if count > n // 2:
            return num

    raise ValueError(
        "No majority element found"
    )  # Should never happen with valid input


# Test cases
def test_majority_element():
    assert majority_element([2, 8, 7, 2, 2, 5, 2, 3, 1, 2, 2]) == 2
    assert majority_element([3, 3, 4, 2, 3, 3, 3, 5, 3, 3]) == 3
    assert majority_element([1, 1, 1, 1, 2, 3, 4, 1, 1, 1]) == 1
    assert majority_element([5, 5, 5, 5, 5, 6, 7, 8, 5, 5, 5]) == 5
    print("All tests passed!")


# Run tests
test_majority_element()

"""
Time Complexity Analysis:
- Counting occurrences takes O(n) time.
- Checking for the majority element takes O(n) time.
- Overall complexity: O(n).

Space Complexity Analysis:
- The Counter dictionary stores up to n elements, leading to O(n) space complexity.
"""
