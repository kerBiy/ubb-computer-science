from domain.entity import TvShow


class RepoError(Exception):
    pass


class Repository:
    def __init__(self, file_name: str) -> None:
        self.__file_name = file_name
        self.__items = []
        self.__load_items()

    @property
    def items(self) -> list:
        return self.__items

    def __load_items(self) -> None:
        with open(self.__file_name, "r") as file:
            for line in file:
                record = line.strip().split(",")
                new_item = TvShow(record[0], record[1], int(record[2]), record[3])
                self.items.append(new_item)

    def __save_items(self) -> None:
        with open(self.__file_name, "w") as file:
            for item in self.__items:
                new_line = (
                    f"{item.name},{item.type},{item.screen_time},{item.description}\n"
                )
                file.write(new_line)

    def __find(self, name: str, type: str) -> int:
        for index, item in enumerate(self.items):
            if item.name == name and item.type == type:
                return index
        return None

    def delete(self, name: str, type: str) -> None:
        index = self.__find(name, type)

        if index is None:
            raise RepoError("The tv show is not in the data base.")

        self.items.pop(index)
        self.__save_items()

    def modify(self, new_item: TvShow) -> None:
        index = self.__find(new_item.name, new_item.type)

        if index is None:
            raise RepoError("The tv show is not in the data base.")

        self.items[index] = new_item
        self.__save_items()

    