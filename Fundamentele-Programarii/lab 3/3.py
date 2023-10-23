def longestPrimIntreEleSubSeq(nums: list[int]) -> list[int]:
    max_length, curr_length = 0, 1
    start_index = start_max = 0

    def cmmdc(a: int, b: int) -> int:
        if b == 0:
            return a
        return cmmdc(b, a % b)

    for i in range(1, len(nums)):
        if cmmdc(nums[i], nums[i - 1]) == 1:
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
    assert longestPrimIntreEleSubSeq([]) == []
    print("Test 0 pass")

    # TEST 1: One element list
    assert longestPrimIntreEleSubSeq([5]) == [5]
    print("Test 1 pass")

    # TEST 2: Ordinary List
    assert longestPrimIntreEleSubSeq([5, 7, 10, 12, 15]) == [5, 7, 10]
    print("Test 2 pass")

    # TEST 3: All list satisfice the condition
    assert longestPrimIntreEleSubSeq([3, 5, 3, 5, 3, 5]) == [3, 5, 3, 5, 3, 5]
    print("Test 3 pass")

    # TEST 4: No two elements are prime between one another
    assert longestPrimIntreEleSubSeq([4, 8, 10, 14, 16]) == [4]
    print("Test 4 pass")


if __name__ == "__main__":
    test_function()
