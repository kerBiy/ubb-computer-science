# Pentru un șir cu n numere întregi care conține și duplicate, să se determine elementul majoritar (care apare de mai mult de n / 2 ori). De ex. 2 este elementul majoritar în șirul [2,8,7,2,2,5,2,3,1,2,2].


def majority_elem(lst: list) -> int:
    """
    Finds the majority element in a list using dictionary frequency counting.
    :param lst: List of integers containing a possible majority element.
    :return: The majority element if found, else -1.
    """
    freq = {}

    for elem in lst:
        freq[elem] = freq.get(elem, 0) + 1

    for elem, count in freq.items():
        if count > len(lst) // 2:
            return elem

    return -1


# Test cases
def test_majority_elem():
    assert majority_elem([2, 8, 7, 2, 2, 5, 2, 3, 1, 2, 2]) == 2
    assert majority_elem([3, 3, 4, 2, 3, 3, 3, 5, 3, 3]) == 3
    assert majority_elem([1, 1, 1, 1, 2, 3, 4, 1, 1, 1]) == 1
    assert majority_elem([5, 5, 5, 5, 5, 6, 7, 8, 5, 5, 5]) == 5
    assert majority_elem([1, 2, 3, 4, 5]) == -1  # No majority element
    print("All tests passed!")


# Run tests
test_majority_elem()

"""
Time Complexity Analysis:
- Iterating over the list to count occurrences takes O(n).
- Checking for the majority element in the dictionary takes O(n).
- Overall complexity: O(n).

Space Complexity Analysis:
- The dictionary stores up to n elements, leading to O(n) space complexity.
"""
