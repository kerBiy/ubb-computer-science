from domain.entity import RealEstate
from infrastructure.repository import Repository


class ServiceError(Exception):
    pass


class Service:
    def __init__(self, repository: Repository) -> None:
        self.__repository = repository

    def add_real_estate(
        self, id: int, address: str, desired_price: float, offer_type: str
    ) -> None:
        """
        Ads a new real estate to the database
        """
        new_real_estate = RealEstate(id, address, desired_price, offer_type)
        self.__repository.add(new_real_estate)

    def average_price(self, offer_type: str) -> float:
        """
        Returns the average of the real estate in the offer_type category
        """
        same_offer_items = [
            item for item in self.__repository.items if item.offer_type == offer_type
        ]

        sum = 0
        for item in same_offer_items:
            sum += item.desired_price

        return sum / len(same_offer_items)

    def __calculate_commission(self, offer_type: str, price: float) -> float:
        """
        Returns the commission of the transaction.
            - If the item is "chirie" than it return 50% of the price
            - If the item is "vanzare" then it return 2% of the price
        """
        if offer_type == "chirie":
            return (1 / 2) * price
        return (2 / 100) * price

    def make_transaction(self, id: int, price: float) -> tuple:
        """
        It buys or rets the real estate with the id specified.
        Return: a tuple with (address, commission)
        Error: Raises a Service Error in case there is no item with that id
        """
        sold_item = self.__repository.find(id)

        if not sold_item:
            raise ServiceError("There is not item with this id in the database.")

        address = sold_item.address
        commission = self.__calculate_commission(sold_item.offer_type, price)
        self.__repository.delete(sold_item.id)

        return address, commission
