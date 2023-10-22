def longestMountainSubSeq(nums: list[int]) -> list[int]:
    if not nums:
        return []

    max_seq, curr_seq = [], [nums[0]]
    is_goingUp = True

    for i in range(1, len(nums)):
        if is_goingUp:
            if nums[i] > nums[i - 1]:
                curr_seq.append(nums[i])
            elif nums[i] < nums[i - 1]:
                is_goingUp = False
                curr_seq.append(nums[i])
            else:
                curr_seq = [nums[i]]
        else:
            if nums[i] < nums[i - 1]:
                curr_seq.append(nums[i])
            else:
                is_goingUp = True
                curr_seq = [nums[i - 1], nums[i]]

        if len(curr_seq) > len(max_seq):
            max_seq = curr_seq

    return max_seq


def test_function():
    # TEST 0: Empty List
    assert longestMountainSubSeq([]) == []
    print("Test 0 pass")

    # TEST 1: All ascending
    assert longestMountainSubSeq([4, 8, 10, 14, 16]) == [4, 8, 10, 14, 16]
    print("Test 1 pass")

    # TEST 2: Mixed List
    assert longestMountainSubSeq([4, 5, 3, 4, 4, 4, 2]) == [4, 5, 3]
    print("Test 2 pass")

    # TEST 3: Same elements list
    assert longestMountainSubSeq([3, 3, 3, 3, 3]) == [3]
    print("Test 3 pass")

    # TEST 4: Two sequence with the same number of elements
    assert longestMountainSubSeq([2, 5, 10, 4, 5, 3, 2]) == [2, 5, 10, 4]
    print("Test 4 pass")


if __name__ == "__main__":
    test_function()
