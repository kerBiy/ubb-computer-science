from domain.entity import Examen


class Repository:
    def __init__(self, file_name: str) -> None:
        self.__file_name = file_name
        self.__items = []
        self.__load_items()

    @property
    def items(self) -> list[Examen]:
        return self.__items

    def __load_items(self) -> None:
        with open(self.__file_name, "r") as file:
            for line in file:
                args = line.strip().split(",")
                new_examen = Examen(
                    args[0], args[1], args[2], True if args[3] == "True" else False
                )
                self.items.append(new_examen)

    def __save_items(self) -> None:
        with open(self.__file_name, "w") as file:
            for item in self.items:
                file.write(f"{str(item)}\n")

    def add(self, new_examen: Examen) -> None:
        self.items.append(new_examen)
        self.__save_items()
