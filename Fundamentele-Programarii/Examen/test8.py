# Folosind metoda Divide et impera scrieți o funcție pură care verifică dacă o listă de numere conține cel puțin un număr par. Datele trebuie împărțite in 2 parți egale la fiecare pas. Ex: [1,3,4,5] -> Adevărat (2p).


def div(nums):
    if len(nums) == 1:
        if nums[0] % 2 == 0:
            return True
        return False

    mid = len(nums) // 2
    return div(nums[mid:]) or div(nums[:mid])


print(div([1, 3, 3, 1]))
