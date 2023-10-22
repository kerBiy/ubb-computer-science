def longestPrimeSubSeq(nums: list[int]) -> list[int]:
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

    for num in nums:
        if is_prim(num):
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
    assert longestPrimeSubSeq([]) == []
    print("Test 0 pass")

    # TEST 1: No prime numbers
    assert longestPrimeSubSeq([4, 8, 10, 14, 16]) == []
    print("Test 1 pass")

    # TEST 2: Mixed List
    assert longestPrimeSubSeq([5, 7, 10, 3, 11, 2, 4]) == [3, 11, 2]
    print("Test 2 pass")

    # TEST 3: Same length sequence
    assert longestPrimeSubSeq([2, 3, 5, 6, 3, 7, 11]) == [2, 3, 5]
    print("Test 3 pass")


if __name__ == "__main__":
    test_function()
