def longestEqualSubSeq(nums: list[int]) -> list[int]:
    max_length, curr_length = 0, 1
    start_index = start_max = 0

    for i in range(1, len(nums)):
        if nums[i] == nums[i - 1]:
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
    assert longestEqualSubSeq([]) == []
    print("Test 0 pass")

    # TEST 1: Different Numbers
    assert longestEqualSubSeq([4, 8, 10, 14, 16]) == [4]
    print("Test 1 pass")

    # TEST 2: Mixed List
    assert longestEqualSubSeq([5, 5, 3, 4, 4, 4, 2]) == [4, 4, 4]
    print("Test 2 pass")

    # TEST 3: All list
    assert longestEqualSubSeq([3, 3, 3, 3, 3]) == [3, 3, 3, 3, 3]
    print("Test 3 pass")

    # TEST 4: Two sequence with the same number of elements
    assert longestEqualSubSeq([2, 2, 2, 5, 5, 7, 7, 7, 8]) == [2, 2, 2]
    print("Test 4 pass")


if __name__ == "__main__":
    test_function()
