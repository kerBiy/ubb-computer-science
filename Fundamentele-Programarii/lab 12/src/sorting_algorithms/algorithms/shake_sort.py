from sorting_algorithms.algorithms.generic_sort import GenericSort


class ShakeSort(GenericSort):
    def __init__(self, iterable, key, reverse) -> None:
        super().__init__(iterable, key, reverse)

    def sort(self) -> None:
        forward = range(len(self.iterable) - 1)
        while True:
            for indices in (forward, list(reversed(forward))):
                swapped = False

                for i in indices:
                    if not self._cmp(self.iterable[i], self.iterable[i + 1]):
                        self.iterable[i], self.iterable[i + 1] = (
                            self.iterable[i + 1],
                            self.iterable[i],
                        )
                        swapped = True

                if not swapped:
                    return

    # def sort(self) -> None:
    #     start = 0
    #     end = len(self.iterable) - 1

    #     swapped = True
    #     while swapped:
    #         # Reset the swapped flag
    #         swapped = False

    #         # Perform the forward pass (left to right)
    #         for i in range(start, end):
    #             if not self._cmp(self.iterable[i], self.iterable[i + 1]):
    #                 self.iterable[i], self.iterable[i + 1] = (
    #                     self.iterable[i + 1],
    #                     self.iterable[i],
    #                 )
    #                 swapped = True

    #         # If nothing moved, the array is already sorted
    #         if not swapped:
    #             return

    #         # Reset the swapped flag
    #         swapped = False

    #         # Perform the backward pass (right to left)
    #         for i in reversed(range(start, end)):
    #             if not self._cmp(self.iterable[i], self.iterable[i + 1]):
    #                 self.iterable[i], self.iterable[i + 1] = (
    #                     self.iterable[i + 1],
    #                     self.iterable[i],
    #                 )
    #                 swapped = True

    #         # Decrease the end point
    #         end -= 1
    #         # Increase the starting point
    #         start += 1
