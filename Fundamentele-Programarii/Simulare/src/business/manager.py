from infrastructure.repository import Repository
from domain.entity import Location


class Manager:
    def __init__(self, repository: Repository) -> None:
        self.__repository = repository

    def filter(self, budget: float, city: str) -> list:
        return self.__repository.filter(budget, city)

    def rent(self, id: int) -> Location:
        location = self.__repository.rent(id)
        price = location.price + location.warranty + location.price / 2
        return price
