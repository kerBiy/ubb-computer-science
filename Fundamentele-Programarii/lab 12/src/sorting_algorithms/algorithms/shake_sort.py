from sorting_algorithms.algorithms.generic_sort import GenericSort


class ShakeSort(GenericSort):
    def __init__(self, iterable, key, reverse) -> None:
        super().__init__(iterable, key, reverse)

    def sort(self) -> None:
        up = range(len(self.iterable) - 1)
        while True:
            for indices in (up, reversed(up)):
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
