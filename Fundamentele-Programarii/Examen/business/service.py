from copy import deepcopy
from datetime import datetime
from domain.entity import Tractor
from infrastructure.repository import Repository


class ServiceError(Exception):
    pass


class Service:
    def __init__(self, repository: Repository) -> None:
        self.__repository = repository
        self.__history = [deepcopy(self.__repository.get_all)]
        self.__filter = ("", -1)

    @property
    def filter(self) -> tuple:
        return self.__filter

    @filter.setter
    def filter(self, new_filter: tuple) -> None:
        self.__filter = new_filter

    def add_tractor(
        self, id: int, name: str, price: float, model: str, date: str
    ) -> None:
        """
        Adds a tractor if the id is different
        Raise: Service Error if the new id is found on the database
        """
        if self.__repository.find(id):
            raise ServiceError("The id is already in the database.")

        new_item = Tractor(id, name, price, model, date)
        self.__repository.add(new_item)

    def __contains(self, num: int, digit: int) -> bool:
        """
        Verifies if the num contains the digit
        """
        if not num:
            return False
        if num % 10 == digit:
            return True

        return self.__contains(num // 10, digit)

    def delete_by_price(self, digit: int) -> int:
        """
        Deletes all the tractors that contains the digit given as parameter in the price
        Return: the number of deletion completed
        """
        list_index = []

        for tractor in self.__repository.get_all.values():
            if self.__contains(tractor.price, digit):
                list_index.append(tractor.id)

        for index in list_index:
            self.__repository.delete(index)

        return len(list_index)

    def __expire(self, date: str) -> bool:
        """
        Verifies if the date is within a year if it is returns True else False
        """
        now = datetime.now().date()
        new_date = datetime.strptime(date, "%d:%m:%Y").date()

        return abs(new_date - now).days > 365

    def filtered_list(self) -> list:
        """
        Returns a filtered list with the self.filter condition
        """
        output = []

        for item in self.__repository.get_all.values():
            if self.filter[0] in item.name and item.price <= self.filter[1]:
                output.append(deepcopy(item))
                if self.__expire(item.date):
                    output[-1].name = "*" + output[-1].name

        return output

    def update_history(self) -> None:
        """
        This function updates the self.history if there happened a change in the repo
        """
        if self.__repository.get_all != self.__history[-1]:
            self.__history.append(deepcopy(self.__repository.get_all))

    def __can_undo(self) -> bool:
        """
        Return if you can undo aka if the len of history is greater than 1 (the original list)
        """
        return len(self.__history) > 1

    def undo_command(self) -> None:
        """
        It undoes the last operation using deep copy
        """
        if not self.__can_undo():
            raise ServiceError("You can not undo any further.")

        self.__history.pop()
        self.__repository.get_all = deepcopy(self.__history[-1])
        self.__repository.save_items()
