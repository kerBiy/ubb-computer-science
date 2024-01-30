class RealEstate:
    def __init__(
        self, id: int, address: str, desired_price: float, offer_type: str
    ) -> None:
        self.__id = id
        self.__address = address
        self.__desired_price = desired_price
        self.__offer_type = offer_type

    def __str__(self) -> str:
        return f"{self.id},{self.address},{self.desired_price},{self.offer_type}"

    @property
    def id(self) -> int:
        return self.__id

    @property
    def address(self) -> str:
        return self.__address

    @property
    def desired_price(self) -> float:
        return self.__desired_price

    @property
    def offer_type(self) -> str:
        return self.__offer_type


"""
Lap1: reading (6:30)
Lap2: Coding main and entity (7:00)
Lap3: Repository (9:00)
Lap4: Console and Service (23:00)
Lap5: Made add (error) (16:00)
Lap6: Made the average functionality (15:00)
Lap7: Made the transaction functionality (16:00)
Lap8: Tests domain (6:00)
Total: 1:40
"""
