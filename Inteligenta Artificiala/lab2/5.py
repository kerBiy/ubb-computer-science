# Pentru un șir cu n elemente care conține valori din mulțimea {1, 2, ..., n - 1} astfel încât o singură valoare se repetă de două ori, să se identifice acea valoare care se repetă. De ex. în șirul [1,2,3,4,2] valoarea 2 apare de două ori.


def repeating_elem(lst: list) -> int:
    """
    Finds the duplicate number in a list where numbers are from {1, 2, ..., n-1}
    and exactly one value is duplicated once.
    :param nums: List of integers containing one duplicate.
    :return: The duplicate integer.
    """
    s = sum(elem for elem in lst)

    n = len(lst)
    seq_sum = ((n - 1) * n) // 2

    return s - seq_sum


def test_repeating_elem():
    assert repeating_elem([1, 2, 3, 4, 2]) == 2
    assert repeating_elem([5, 3, 1, 4, 3, 2]) == 3
    assert repeating_elem([7, 2, 6, 4, 5, 6, 1, 3]) == 6
    assert repeating_elem([1, 1]) == 1
    assert repeating_elem([2, 3, 4, 5, 6, 2, 1]) == 2
    print("All tests passed!")


test_repeating_elem()

"""
Time Complexity Analysis:
- The overall complexity is O(n), where n is the length of the array.

Space Complexity Analysis:
- O(1) because it doesn't store many variables
"""
