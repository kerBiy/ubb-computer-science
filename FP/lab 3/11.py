def maxSumSubSeq(nums: list[int]) -> list[int]:
    if not nums:
        return []

    max_sum = float("-inf")
    left = right = temp_left = 0
    curr_sum = 0

    for i, num in enumerate(nums):
        curr_sum += num

        if curr_sum > max_sum:
            max_sum = curr_sum
            left = temp_left
            right = i

        if curr_sum < 0:
            curr_sum = 0
            temp_left = i + 1

    return nums[left : right + 1]


def test_function():
    # TEST 0: Empty List
    assert maxSumSubSeq([]) == []
    print("Test 0 pass")

    # TEST 1: All negative numbers
    assert maxSumSubSeq([-2, -3, -1, -5, -4]) == [-1]
    print("Test 1 pass")

    # TEST 2: Mixed List
    assert maxSumSubSeq([-2, 1, -3, 4, -1, 2, 1, -5, 4]) == [4, -1, 2, 1]
    print("Test 2 pass")

    # TEST 3: Single pozitiv number
    assert maxSumSubSeq([5]) == [5]
    print("Test 3 pass")


if __name__ == "__main__":
    test_function()
