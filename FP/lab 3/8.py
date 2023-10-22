def longestOnlyDigitsSubSeq(nums: list[int]) -> list[int]:
    max_seq, curr_seq = [], []

    for num in nums:
        if 0 <= num <= 10:
            curr_seq.append(num)
        else:
            if len(curr_seq) > len(max_seq):
                max_seq = list(curr_seq)
            curr_seq = []

    if len(curr_seq) > len(max_seq):
        max_seq = list(curr_seq)

    return max_seq


def test_function():
    # TEST 0: Empty List
    assert longestOnlyDigitsSubSeq([]) == []
    print("Test 0 pass")

    # TEST 1: Regular List
    assert longestOnlyDigitsSubSeq([4, 8, 10, 14, 16]) == [4, 8, 10]
    print("Test 1 pass")

    # TEST 2: Mixed List
    assert longestOnlyDigitsSubSeq([5, 5, 3, 45, 4, 4, 2]) == [5, 5, 3]
    print("Test 2 pass")

    # TEST 3: No elements
    assert longestOnlyDigitsSubSeq([12, 231, 532, 342]) == []
    print("Test 3 pass")


if __name__ == "__main__":
    test_function()
