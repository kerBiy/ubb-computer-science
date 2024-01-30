from domain.entity import RealEstate


class Test:
    def __init__(self) -> None:
        pass

    def __domain_tests(self) -> None:
        print("Starting domain tests...")

        self.__id = 12
        self.__address = "str. Nigger mare si tare"
        self.__desired_price = 90000
        self.__offer_type = "vanzare"
        self.__real_estate = RealEstate(
            self.__id, self.__address, self.__desired_price, self.__offer_type
        )

        assert self.__real_estate.id == self.__id
        assert self.__real_estate.address == self.__address
        assert self.__real_estate.desired_price == self.__desired_price
        assert self.__real_estate.offer_type == self.__offer_type

        print("Domain tests ran successfully.")

    def run_all(self) -> None:
        print("Starting the tests...")
        self.__domain_tests()
        print("All the tests ran successfully.")
