import heapq


def kth_largest_element(arr: list, k: int) -> int:
    """
    Finds the k-th largest element in an array.
    :param arr: List of integers.
    :param k: The k-th largest element to find (1-based index).
    :return: The k-th largest element.
    """
    if not arr or k <= 0 or k > len(arr):
        raise ValueError(
            "Invalid input: k must be between 1 and the length of the array."
        )

    return heapq.nlargest(k, arr)[-1]


# Test cases
def test_kth_largest_element():
    assert kth_largest_element([7, 4, 6, 3, 9, 1], 2) == 7
    assert kth_largest_element([10, 20, 30, 40, 50], 3) == 30
    assert kth_largest_element([5, 3, 1, 2, 4], 1) == 5
    assert kth_largest_element([8, 6, 7, 5, 3, 0, 9], 4) == 6
    assert kth_largest_element([100, 200, 300, 400, 500], 5) == 100
    print("All tests passed!")


# Run tests
test_kth_largest_element()

"""
Time Complexity Analysis:
- `heapq.nlargest(k, arr)` creates a max heap of size k and retrieves the k-largest elements, which runs in O(n log k).
- Since `k` is generally much smaller than `n`, this is more efficient than sorting (O(n log n)).

Space Complexity Analysis:
- The function uses a heap of size `k`, so the space complexity is O(k).
"""
