from sorting_algorithms.algorithm import Algorithm


class Sorting:
    @staticmethod
    def sort(
        iterable: list, key=None, reverse=False, algorithm=Algorithm.SELECTION_SORT
    ) -> None:
        sorting_algorithm = algorithm.value(iterable, key, reverse)
        sorting_algorithm.sort()
