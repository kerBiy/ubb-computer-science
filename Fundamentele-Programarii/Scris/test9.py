# 4 Folosind metoda Divide et impera scrieți o funcție pură care inversează o lista de numere. Datele trebuie împărțite in 2 parți egale la fiecare pas. Ex. [1,2,3,4] -> [4,3,2,1] (2p).


def div(nums):
    if len(nums) == 1:
        return nums

    mid = len(nums) // 2
    left = div(nums[:mid])
    right = div(nums[mid:])
    return right + left


print(div([1, 2, 3, 4]))
