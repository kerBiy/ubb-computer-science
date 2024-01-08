from sys import exit
from infrastructure.repository import Repository
from domain.validate import Validator


class Manager:
    def __init__(self, furniture_repo: Repository, validator: Validator) -> None:
        self.__repository = furniture_repo
        self.__validator = validator

    def validate_file_items(self) -> bool:
        return self.__validator.validate_all(self.__repository.get_all())

    def search(self, object_type: str) -> list:
        return self.__repository.search(object_type)

    def buy(self, code: int, count: int) -> None:
        furniture = self.__repository.search_code(code)

        if not furniture:
            raise Exception(f"The code {code} does not exist.")
        if count > furniture.stock:
            raise Exception("We don't have that many items on the stock.")

        self.__repository.update(code, count)
