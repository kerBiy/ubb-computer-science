def div(nums):
    """
    Functia div calculeaza numarul de numere negative din nums

    param: nums - o lista de numere
    param_type: list
    return: numarul de numere negative
    return_type: int
    """
    if nums is None or nums == []:
        return 0

    if len(nums) == 1:
        if nums[0] < 0:
            return 1
        return 0

    mid = len(nums) // 2
    return div(nums[:mid]) + div(nums[mid:])


print(div([-1, 2, 3, 0, -3, -23, 0, 1]))
