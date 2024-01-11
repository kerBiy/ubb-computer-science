class RecursiveBack:
    def __init__(self) -> None:
        pass

    def back(
        self, nums: list[int], index: int = 0, curr_subsequence: list[int] = []
    ) -> None:
        """
        Shows all the increasing subsequences in the list.
        """
        print(curr_subsequence)

        for i in range(index, len(nums)):
            if not curr_subsequence or nums[i] > curr_subsequence[-1]:
                self.back(nums, i + 1, curr_subsequence + [nums[i]])
