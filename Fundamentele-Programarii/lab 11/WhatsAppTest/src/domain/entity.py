class Furniture:
    def __init__(
        self, code: str, object_type: str, name: str, stock: int, price: float
    ) -> None:
        self.__code = code
        self.__type = object_type
        self.__name = name
        self.__stock = stock
        self.__price = price

    def __str__(self) -> str:
        return f"{self.code},{self.type},{self.name},{self.stock},{self.price}"

    @property
    def code(self) -> str:
        return self.__code

    @property
    def type(self) -> str:
        return self.__type

    @property
    def name(self) -> str:
        return self.__name

    @property
    def stock(self) -> int:
        return self.__stock

    @property
    def price(self) -> float:
        return self.__price

    def update_stock(self, value: int) -> None:
        self.__stock -= value
