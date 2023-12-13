class Location:
    def __init__(
        self, id: int, address: str, city: str, price: float, warranty: float
    ) -> None:
        self.__id = id
        self.__address = address
        self.__city = city
        self.__price = price
        self.__warranty = warranty

    def __str__(self) -> str:
        return f"{self.id},{self.address},{self.city},{self.price},{self.warranty}"

    def __eq__(self, __value: object) -> bool:
        return (
            isinstance(__value, object)
            and self.id == __value.id
            and self.address == __value.address
            and self.city == __value.city
            and self.price == __value.price
            and self.warranty == __value.warranty
        )

    @property
    def id(self) -> int:
        return self.__id

    @property
    def address(self) -> str:
        return self.__address

    @property
    def city(self) -> str:
        return self.__city

    @property
    def price(self) -> float:
        return self.__price

    @property
    def warranty(self) -> float:
        return self.__warranty
