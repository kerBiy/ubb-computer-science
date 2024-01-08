from sorting_algorithms.algorithm import Algorithm


class Sorting:
    @staticmethod
    def sort(
        iterable: list,
        key=None,
        reverse=False,
        algorithm=Algorithm.SELECTION_SORT,
        cmp=None,
    ) -> None:
        sorting_algorithm = algorithm.value(iterable, key, reverse, cmp)
        sorting_algorithm.sort()
