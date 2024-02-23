def div(nums, start, end):
    """
    Functia calculeaza produsul numerelor de pe pozitii pare
    params: nums - o lista de numere, start - de unde incepem (default 0), end - ultimul element (default len(nums) - 1)
    param_type nums: list, start: int, end: int
    return: produsul nr de pe pozitii pare
    return_type: int
    raises ValueError daca lista e vida.
    """
    if nums is None or nums == []:
        raise ValueError("Lista e goala")

    if start == end:
        return nums[start] if start % 2 == 0 else 1

    mid = (start + end) // 2
    return div(nums, start, mid) * div(nums, mid + 1, end)


print(div([1, 2, 3, 4, 5], 0, 4))
