from domain.entity import Tractor


class Repository:
    def __init__(self, file_name: str) -> None:
        self.__file_name = file_name
        self.__items = {}
        self.__load_items()

    @property
    def get_all(self) -> dict:
        return self.__items

    @get_all.setter
    def get_all(self, another) -> None:
        self.__items = another

    def __len__(self) -> int:
        return len(self.__items)

    def __load_items(self) -> None:
        """
        Loads all the records from the database into the self.__items dict
        """
        with open(self.__file_name, "r") as file:
            for line in file:
                args = line.strip().split(",")
                new_item = Tractor(
                    int(args[0]), args[1], float(args[2]), args[3], args[4]
                )
                self.__items[new_item.id] = new_item

    def save_items(self) -> None:
        """
        Save all the items in self.__items into the database
        """
        with open(self.__file_name, "w") as file:
            for item in self.get_all.values():
                file.write(f"{item}\n")

    def add(self, new_item: Tractor) -> None:
        self.__items[new_item.id] = new_item
        self.save_items()

    def delete(self, item_id: int) -> None:
        del self.__items[item_id]
        self.save_items()

    def find(self, item_id: int) -> Tractor:
        return self.__items.get(item_id, None)

    def clear(self) -> None:
        self.__items = {}
        self.save_items()
