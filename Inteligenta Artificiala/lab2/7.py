# Să se determine al k-lea cel mai mare element al unui șir de numere cu n elemente (k < n). De ex. al 2-lea cel mai mare element din șirul [7,4,6,3,9,1] este 7.

import heapq

def kth_largest_elem(lst: list, k: int) -> int:
    """
    Finds the k-th largest element using a max heap.
    :param lst: List of integers.
    :param k: The k-th largest element to find.
    :return: The k-th largest element.
    """
    max_heap = [-x for x in lst]
    heapq.heapify(max_heap)

    for _ in range(k):
        rezultat = -heapq.heappop(max_heap)

    return rezultat


# Test cases
def test_kth_largest_elem():
    assert kth_largest_elem([7, 4, 6, 3, 9, 1], 2) == 7
    assert kth_largest_elem([10, 20, 30, 40, 50], 3) == 30
    assert kth_largest_elem([5, 3, 1, 2, 4], 1) == 5
    assert kth_largest_elem([8, 6, 7, 5, 3, 0, 9], 4) == 6
    assert kth_largest_elem([100, 200, 300, 400, 500], 5) == 100
    print("All tests passed!")


# Run tests
test_kth_largest_elem()

"""
Time Complexity Analysis:
- Creating the max heap using list comprehension: O(n).
- Converting the list into a heap with `heapify`: O(n).
- Extracting `k` elements from the heap: O(k log n).
- Overall complexity: O(n + k log n), which is efficient for small values of `k`.

Space Complexity Analysis:
- Storing the heap requires O(n) space.
- The function does not use additional significant memory, so total space complexity is O(n).
"""
