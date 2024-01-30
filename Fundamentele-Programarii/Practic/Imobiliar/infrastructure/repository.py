from domain.entity import RealEstate


class Repository:
    def __init__(self, file_name: str) -> None:
        self.__file_name = file_name
        self.__items = {}
        self.__load_items()

    @property
    def items(self) -> dict:
        """
        Returns a list of the real estate from the database
        """
        return self.__items.values()

    def __load_items(self) -> None:
        """
        Loads all the items from the file path self.__file_name
        """
        with open(self.__file_name, "r") as file:
            for line in file:
                args = line.strip().split(",")
                new_item = RealEstate(int(args[0]), args[1], float(args[2]), args[3])
                self.__items[new_item.id] = new_item

    def __save_items(self) -> None:
        """
        Saves all the items from self.__items in the database
        """
        with open(self.__file_name, "w") as file:
            for item in self.items:
                file.write(f"{item}\n")

    def add(self, new_item: RealEstate) -> None:
        """
        Adds an item to the database
        """
        self.__items[new_item.id] = new_item
        self.__save_items()

    def delete(self, id: int) -> None:
        """
        Removes an item from the database
        """
        del self.__items[id]
        self.__save_items()

    def find(self, id: int) -> RealEstate:
        """
        Returns an item from the database with the id given as parameter
        """
        return self.__items.get(id, None)
