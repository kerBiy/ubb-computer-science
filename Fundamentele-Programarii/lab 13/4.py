# Rezolvați problema folosind BACKTRACKING, scrieți o varianta recursivă și una iterativă.
# Se dă o listă de numere întregi a1,...an, determinați toate sub-secvențele (ordinea elementelor este menținută) strict crescătoare.


def recursive_btk(
    nums: list[int], index: int = 0, curr_subsequence: list[int] = []
) -> None:
    print(curr_subsequence)

    for i in range(index, len(nums)):
        if not curr_subsequence or nums[i] > curr_subsequence[-1]:
            recursive_btk(nums, i + 1, curr_subsequence + [nums[i]])


def iterative_btk(nums):
    output = [[]]

    for num in nums:
        new_subsequence = []
        for subsequence in output:
            if not subsequence or num > subsequence[-1]:
                new_subsequence.append(subsequence + [num])

        output.extend(new_subsequence)

    for subsequence in output:
        print(subsequence)


lista = [1, 3, 2, 4]
recursive_btk(lista)
iterative_btk(lista)
