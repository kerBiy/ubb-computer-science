def longestDistinctSubSeq(nums: list[int]) -> list[int]:
    hashset = set()
    start_index = start_max = 0
    max_length = 0

    for end_index, element in enumerate(nums):
        while element in hashset:
            hashset.remove(nums[start_index])
            start_index += 1

        hashset.add(element)

        curr_length = end_index - start_index + 1
        if max_length < curr_length:
            start_max = start_index
            max_length = curr_length

    return nums[start_max : start_max + max_length]


def test_function():
    # TEST 0: Empty List
    assert longestDistinctSubSeq([]) == []
    print("Test 0 pass")

    # TEST 1: Different Numbers
    assert longestDistinctSubSeq([4, 8, 10, 14]) == [4, 8, 10, 14]
    print("Test 1 pass")

    # TEST 2: Repeating Elements
    assert longestDistinctSubSeq([1, 2, 2, 3, 3, 4, 5]) == [3, 4, 5]
    print("Test 2 pass")

    # TEST 3: All list
    assert longestDistinctSubSeq([3, 3, 3, 3, 3]) == [3]
    print("Test 3 pass")

    # TEST 4: Regular List
    assert longestDistinctSubSeq([1, 2, 3, 2, 3, 4, 5]) == [2, 3, 4, 5]
    print("Test 4 pass")


if __name__ == "__main__":
    test_function()
