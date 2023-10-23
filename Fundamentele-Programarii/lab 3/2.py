# Contine cel mult trei valori distincte


def longestSubSeqWithMax3Elem(nums: list[int]) -> list[int]:
    if not nums:
        return []

    curr_seq = [nums[0]]
    max_seq = [nums[0]]

    for i in range(1, len(nums)):
        curr_seq.append(nums[i])

        while len(set(curr_seq)) > 3:
            curr_seq.pop(0)

        if len(curr_seq) > len(max_seq):
            max_seq[:] = curr_seq

    return max_seq


def test_case():
    assert longestSubSeqWithMax3Elem([]) == []
    assert longestSubSeqWithMax3Elem([2]) == [2]
    assert longestSubSeqWithMax3Elem([2, 3, 2, 5]) == [2, 3, 2, 5]
    assert longestSubSeqWithMax3Elem([2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 5]) == [
        3,
        3,
        3,
        4,
        4,
        4,
        5,
        5,
        5,
        5,
    ]
    assert longestSubSeqWithMax3Elem([2, 3, 4, 5, 5, 2, 2, 3]) == [4, 5, 5, 2, 2]


test_case()
print("pass")
