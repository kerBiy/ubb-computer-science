from sorting_algorithms.sorting import Sorting
from sorting_algorithms.algorithm import Algorithm
from domain.recursive import Recursive


class Person:
    def __init__(self, name: str, age: int):
        self.__name = name
        self.__age = age

    @property
    def name(self) -> str:
        return self.__name

    @property
    def age(self) -> int:
        return self.__age

    def __str__(self) -> str:
        return self.name + " " + str(self.age)


class Test:
    @staticmethod
    def run_tests() -> None:
        Test.test_selection_sort()
        Test.test_shake_sort()
        Test.test_recursive_function()
        print("All tests passed")

    @staticmethod
    def test_selection_sort() -> None:
        l = [2, 1, 3]
        Sorting.sort(l)
        assert l == [1, 2, 3]

        Sorting.sort(l, reverse=True)
        assert l == [3, 2, 1]

        l = [2, 1, 2, 3, 1]
        Sorting.sort(l)
        assert l == [1, 1, 2, 2, 3]

        Sorting.sort(l, reverse=True)
        assert l == [3, 2, 2, 1, 1]

        p1 = Person("p1", 1)
        p2 = Person("p2", 2)
        p3 = Person("p3", 3)
        p4 = Person("p4", 2)

        # sort by name asc
        l = [p3, p2, p1, p4]
        Sorting.sort(l, key=lambda x: x.name)
        assert l == [p1, p2, p3, p4]

        # sort by age desc
        l = [p3, p2, p4, p1]
        Sorting.sort(l, key=lambda x: x.age, reverse=True)
        assert l == [p3, p2, p4, p1]

        # sort by age asc
        l = [p3, p2, p4, p1]
        Sorting.sort(l, key=lambda x: x.age)
        assert l == [p1, p4, p2, p3]

        # sort by name,age ascending
        l = [p3, p2, p1, p4]
        Sorting.sort(l, key=lambda x: (x.name, x.age))
        assert l == [p1, p2, p3, p4]

        # sort by age descending and by name ascending
        l = [p3, p2, p1, p4]
        Sorting.sort(l, key=lambda x: (-x.age, x.name))
        assert l == [p3, p2, p4, p1]

    @staticmethod
    def test_shake_sort() -> None:
        l = [2, 1, 3]
        Sorting.sort(l, algorithm=Algorithm.SHAKE_SORT)
        assert l == [1, 2, 3]

        Sorting.sort(l, reverse=True, algorithm=Algorithm.SHAKE_SORT)
        assert l == [3, 2, 1]

        l = [2, 1, 2, 3, 1]
        Sorting.sort(l, algorithm=Algorithm.SHAKE_SORT)
        assert l == [1, 1, 2, 2, 3]

        Sorting.sort(l, reverse=True, algorithm=Algorithm.SHAKE_SORT)
        assert l == [3, 2, 2, 1, 1]

        p1 = Person("p1", 1)
        p2 = Person("p2", 2)
        p3 = Person("p3", 3)
        p4 = Person("p4", 2)

        # sort by name asc
        l = [p3, p2, p1, p4]
        Sorting.sort(l, key=lambda x: x.name, algorithm=Algorithm.SHAKE_SORT)
        assert l == [p1, p2, p3, p4]

        # sort by age desc
        l = [p3, p2, p4, p1]
        Sorting.sort(
            l, key=lambda x: x.age, reverse=True, algorithm=Algorithm.SHAKE_SORT
        )
        assert l == [p3, p2, p4, p1]

        # sort by age asc
        l = [p3, p2, p4, p1]
        Sorting.sort(l, key=lambda x: x.age, algorithm=Algorithm.SHAKE_SORT)
        assert l == [p1, p2, p4, p3]

        # sort by name,age ascending
        l = [p3, p2, p1, p4]
        Sorting.sort(l, key=lambda x: (x.name, x.age), algorithm=Algorithm.SHAKE_SORT)
        assert l == [p1, p2, p3, p4]

        # sort by age descending and by name ascending
        l = [p3, p2, p1, p4]
        Sorting.sort(l, key=lambda x: (-x.age, x.name), algorithm=Algorithm.SHAKE_SORT)
        assert l == [p3, p2, p4, p1]

    @staticmethod
    def test_recursive_function() -> None:
        # for 0 elements
        l = [1, 2, 3, 4]
        Recursive.get_20_percent(l, len(l))
        assert l == []

        # only one element
        l = [1, 2, 3, 4, 5]
        Recursive.get_20_percent(l, len(l))
        assert l == [1]

        # for 20 items
        l = list(range(1, 101))
        Recursive.get_20_percent(l, len(l))
        assert l == list(range(1, 21))

        # for reversed 20 items
        l = list(reversed(range(100)))
        Recursive.get_20_percent(l, len(l))
        assert l == list(reversed(range(80, 100)))
