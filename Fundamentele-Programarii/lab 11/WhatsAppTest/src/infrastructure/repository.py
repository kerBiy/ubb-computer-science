from typing import Any
from domain.entity import Furniture


class Repository:
    def __init__(self, file_name: str) -> None:
        self.__file_name = file_name
        self.__items = {}
        self.__load()

    def get_all(self) -> list:
        return self.__items.values()

    def search_code(self, code: str) -> Furniture:
        return self.__items.get(code, None)

    def __load(self) -> None:
        try:
            with open(self.__file_name, "r") as file:
                for line in file:
                    record = line.strip().split(",")
                    new_furniture = Furniture(
                        record[0],
                        record[1],
                        record[2],
                        int(record[3]),
                        float(record[4]),
                    )
                    self.__items[new_furniture.code] = new_furniture

        except Exception as ex:
            print(ex)

    def __save(self) -> None:
        try:
            with open(self.__file_name, "w") as file:
                for furniture in self.__items.values():
                    new_line = f"{furniture.code},{furniture.type},{furniture.name},{furniture.stock},{furniture.price}\n"
                    file.write(new_line)
        except Exception as ex:
            raise Exception(ex)

    def search(self, object_type: int) -> list:
        output = []

        for obj in self.__items.values():
            if obj.type == object_type:
                output.append(obj)

        return output

    def update(self, code: str, count: int) -> None:
        self.__items[code].update_stock(count)
        self.__save()
