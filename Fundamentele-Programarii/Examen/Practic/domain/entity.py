class Tractor:
    def __init__(self, id: int, name: str, price: float, model: str, date: str) -> None:
        self.__id = id
        self.__name = name
        self.__price = price
        self.__model = model
        self.__date = date

    def __str__(self) -> str:
        return f"{self.id},{self.name},{self.price},{self.model},{self.date}"

    def __eq__(self, value: object) -> bool:
        return (
            self.id == value.id
            and self.name == value.name
            and self.price == value.price
            and self.model == value.model
            and self.date == value.date
        )

    @property
    def id(self) -> int:
        return self.__id

    @property
    def name(self) -> str:
        return self.__name

    @name.setter
    def name(self, other_name: str) -> None:
        self.__name = other_name

    @property
    def price(self) -> float:
        return self.__price

    @property
    def model(self) -> str:
        return self.__model

    @property
    def date(self) -> str:
        return self.__date
