def longestOppositeSignsSubSeq(nums: list[int]) -> list[int]:
    max_length, curr_length = 0, 1
    start_index = start_max = 0

    for i in range(1, len(nums)):
        if (nums[i] < 0 and nums[i - 1] >= 0) or (nums[i] >= 0 and nums[i - 1] < 0):
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
    assert longestOppositeSignsSubSeq([]) == []
    print("Test 0 pass")

    # TEST 1: Pozitive Nums
    assert longestOppositeSignsSubSeq([4, 8, 10, 14, 16]) == [4]
    print("Test 1 pass")

    # TEST 2: Mixed List
    assert longestOppositeSignsSubSeq([5, -5, 3, 4, 4, -4, 2]) == [5, -5, 3]
    print("Test 2 pass")

    # TEST 3: All list
    assert longestOppositeSignsSubSeq([3, -3, 3, -3, 3]) == [3, -3, 3, -3, 3]
    print("Test 3 pass")

    # TEST 4: Two sequence with the same number of elements
    assert longestOppositeSignsSubSeq([-2, 2, -2, -5, 5, -7, -7, -7, 8]) == [-2, 2, -2]
    print("Test 4 pass")


if __name__ == "__main__":
    test_function()
