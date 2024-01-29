from copy import deepcopy

from infrastructure.repository import Repository, RepoError
from domain.entity import Book


class ServiceError(Exception):
    pass


class Service:
    def __init__(self, repository: Repository) -> None:
        self.__repository = repository
        self.__history = [deepcopy(self.__repository.items)]
        self.__filter = ("", -1)

    @property
    def filter(self) -> tuple:
        return self.__filter

    @filter.setter
    def filter(self, new_filter: tuple) -> None:
        self.__filter = new_filter

    def filter_list(self) -> list[Book]:
        """
        It filters the list by the self.filter attribute
        Return: a list filtered
        """
        return (
            [
                item
                for item in self.__repository.items
                if self.filter[0] in item.title and item.year <= self.filter[1]
            ]
            if self.filter != ("", -1)
            else self.__repository.items
        )

    def add_book(self, id: int, title: str, author: str, year: int) -> None:
        """
        Adds a new book with the params as proprieties
        """
        new_book = Book(id, title, author, year)
        self.__repository.add(new_book)

    def modify_book(self, digit: int, new_author: str) -> None:
        """
        Modifies the books that have the digit in their ids
        """
        try:
            self.__repository.modify(digit, new_author)
        except RepoError as re:
            print("Repository Error:", re)

    def __can_undo(self) -> bool:
        """
        Verifies if you can undo aka if there is at least the start items in history
        """
        return len(self.__history) > 1

    def update_history(self) -> None:
        """
        It updates the history of the repo. Makes a deep copy
        """
        if self.__history[-1] != self.__repository.items:
            self.__history.append(deepcopy(self.__repository.items))

    def undo_command(self) -> None:
        """
        It perform the undo.
        Raises a ServiceError if you can't undo any further
        """
        if not self.__can_undo():
            raise ServiceError("You can't undo any further.")

        self.__history.pop()
        self.__repository.items = deepcopy(self.__history[-1])
        self.__repository.save_items()
