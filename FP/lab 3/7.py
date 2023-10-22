def longestPrimeDifSubSeq(nums: list[int]) -> list[int]:
    if not nums:
        return []

    max_seq, curr_seq = [], []

    def is_prim(n: int) -> bool:
        if n < 2:
            return False
        if n % 2 == 0 and n != 2:
            return False

        for i in range(3, int(n**0.5), 2):
            if n % i == 0:
                return False

        return True

    for i in range(len(nums) - 1):
        if not curr_seq:
            curr_seq.append(nums[i])

        difference = abs(nums[i + 1] - nums[i])

        if is_prim(difference):
            curr_seq.append(nums[i + 1])
        else:
            if len(curr_seq) > len(max_seq):
                max_seq = list(curr_seq)
            curr_seq = []

    if len(curr_seq) > len(max_seq):
        max_seq = list(curr_seq)

    return max_seq


def test_function():
    # TEST 0: Empty List
    assert longestPrimeDifSubSeq([]) == []
    print("Test 0 pass")

    # TEST 1: No good sequence
    assert longestPrimeDifSubSeq([4, 8, 12, 13, 17]) == [4]
    print("Test 1 pass")

    # TEST 2: Regular list
    assert longestPrimeDifSubSeq([5, 10, 3, 4, 4, 7, 2]) == [5, 10, 3]
    print("Test 2 pass")

    # TEST 3: Same number
    assert longestPrimeDifSubSeq([3, 3, 3, 3, 3]) == [3]
    print("Test 3 pass")


if __name__ == "__main__":
    test_function()
