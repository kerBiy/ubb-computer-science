def find_duplicate(nums: list) -> int:
    """
    Finds the duplicate number in a list where numbers are from {1, 2, ..., n-1}
    and exactly one value is duplicated once.
    :param nums: List of integers containing one duplicate.
    :return: The duplicate integer.
    """
    seen = set()
    for num in nums:
        if num in seen:
            return num
        seen.add(num)

    raise ValueError("No duplicate found")  # Should never happen with valid input


# Test cases
def test_find_duplicate():
    assert find_duplicate([1, 2, 3, 4, 2]) == 2
    assert find_duplicate([5, 3, 1, 4, 3, 2]) == 3
    assert find_duplicate([7, 2, 6, 4, 5, 6, 1, 3]) == 6
    assert find_duplicate([1, 1]) == 1
    assert find_duplicate([2, 3, 4, 5, 6, 2, 1]) == 2
    print("All tests passed!")


# Run tests
test_find_duplicate()

"""
Time Complexity Analysis:
- We iterate through the list once, checking each element in a set, which takes O(1) per lookup.
- The overall complexity is O(n), where n is the length of the array.

Space Complexity Analysis:
- The set stores at most n-1 elements, resulting in O(n) space usage.
"""
