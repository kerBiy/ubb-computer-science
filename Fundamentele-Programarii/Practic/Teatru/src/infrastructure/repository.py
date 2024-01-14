from domain.entity import TheatricalPiece
from domain.validator import Validator


class Repository:
    def __init__(self, file_name: str) -> None:
        self.__file_name = file_name
        self.__items = []
        self.__load_items()

    def __load_items(self) -> None:
        with open(self.__file_name, "r") as file:
            for line in file:
                record = line.strip().split(",")
                new_item = TheatricalPiece(
                    record[0], record[1], record[2], int(record[3])
                )
                self.__items.append(new_item)

    def __save_items(self) -> None:
        with open(self.__file_name, "w") as file:
            for item in self.__items:
                new_line = (
                    f"{item.name},{item.director},{item.genera},{item.screen_time}\n"
                )
                file.write(new_line)

    def __find(self, name: str, director: str) -> int:
        for index, item in enumerate(self.__items):
            if item.name == name and item.director == director:
                return index
        return None

    def add(self, new_item: TheatricalPiece) -> None:
        self.__items.append(new_item)
        self.__save_items()

    def modify(self, new_item: TheatricalPiece) -> None:
        index = self.__find(new_item.name, new_item.director)
        if index is None:
            raise Exception("The theatrical piece is not in the data base.")

        self.__items[index] = new_item
        self.__save_items()

    def generate(self, number_of_items: int) -> list:
        return self.__items
