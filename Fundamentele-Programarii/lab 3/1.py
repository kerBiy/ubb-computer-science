def longestSortedSubSeq(nums: list[int]) -> list[int]:
    max_length, curr_length = 0, 1
    start_index = start_max = 0

    for i in range(1, len(nums)):
        if nums[i] > nums[i - 1]:
            curr_length += 1
        else:
            if curr_length > max_length:
                max_length = curr_length
                start_max = start_index

            curr_length = 1
            start_index = i

    if curr_length > max_length:
        max_length = curr_length
        start_max = start_index

    return nums[start_max : start_max + max_length]


def test_function():
    # TEST 0: Empty List
    assert longestSortedSubSeq([]) == []
    print("Test 0 pass")

    # TEST 1: Regular List
    assert longestSortedSubSeq([1, 2, 3, 5, 2, 4, 9]) == [1, 2, 3, 5]
    print("Test 1 pass")

    # TEST 2: Two sequence of the same size
    assert longestSortedSubSeq([1, 2, 3, 5, 2, 4, 7, 9]) == [1, 2, 3, 5]
    print("Test 2 pass")

    # TEST 3: Equal elements
    assert longestSortedSubSeq([3, 3, 3]) == [3]
    print("Test 3 pass")
    
    # TEST 4: No sequence sitisface the condition
    assert longestSortedSubSeq([5, 4, 3, 2, 1]) == [5]
    print("Test 4 pass")


if __name__ == "__main__":
    test_function()
