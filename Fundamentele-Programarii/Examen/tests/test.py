from business.service import Service
from domain.entity import Tractor
from infrastructure.repository import Repository


class Test:
    def __init__(self) -> None:
        pass

    def __test_domain(self) -> None:
        print("Starting domain tests...")

        self.__id = 10
        self.__name = "Lamborghini"
        self.__price = 200000
        self.__model = "Aventador"
        self.__date = "30:10:2021"

        self.__new_tractor = Tractor(
            self.__id, self.__name, self.__price, self.__model, self.__date
        )

        assert self.__new_tractor.id == self.__id
        assert self.__new_tractor.name == self.__name
        assert self.__new_tractor.price == self.__price
        assert self.__new_tractor.model == self.__model
        assert self.__new_tractor.date == self.__date

        print("Domain tests ran successfully.")

    def __test_infrastructure(self) -> None:
        print("Starting infrastructure tests...")

        # Testing add

        self.__repo = Repository("data/test.txt")

        self.__repo.add(self.__new_tractor)
        assert len(self.__repo) == 1
        assert self.__repo.get_all == {self.__id: self.__new_tractor}

        # Testing delete

        self.__repo.delete(self.__id)
        assert len(self.__repo) == 0
        assert self.__repo.get_all == {}

        self.__repo.clear()

        print("Infrastructure tests ran successfully.")

    def __test_business(self) -> None:
        print("Starting business tests...")

        self.__service = Service(self.__repo)

        # Delete

        self.__repo.add(self.__new_tractor)

        self.__new_id = 11
        self.__new_name = "Pagany"
        self.__new_price = 250000
        self.__new_model = "Huira"
        self.__new_date = "30:03:2022"

        self.__other_tractor = Tractor(
            self.__new_id,
            self.__new_name,
            self.__new_price,
            self.__new_model,
            self.__new_date,
        )

        self.__repo.add(self.__other_tractor)

        self.__service.delete_by_price(2)
        assert len(self.__repo) == 0
        assert self.__repo.get_all == {}

        self.__repo.add(self.__other_tractor)

        self.__service.delete_by_price(3)
        assert len(self.__repo) == 1
        assert self.__repo.get_all == {self.__new_id: self.__other_tractor}

        self.__repo.clear()

        # Filter

        self.__repo.add(self.__new_tractor)
        self.__repo.add(self.__other_tractor)

        self.__service.filter = ("i", 50000)
        new_list = self.__service.filtered_list()

        assert new_list == []

        self.__repo.clear()

        print("Business tests ran successfully.")

    def run_all(self) -> None:
        print("Starting all tests...")
        self.__test_domain()
        self.__test_infrastructure()
        self.__test_business()
        print("All tests ran successfully.")
