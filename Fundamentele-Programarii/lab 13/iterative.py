class IterativeBack:
    def __init__(self) -> None:
        pass

    def back(self, nums: list[int]) -> None:
        """
        Shows all the increasing subsequences in the list.
        """
        output = [[]]

        for num in nums:
            new_subsequence = []
            for subsequence in output:
                if not subsequence or num > subsequence[-1]:
                    new_subsequence.append(subsequence + [num])

            output.extend(new_subsequence)

        for subsequence in output:
            print(subsequence)
