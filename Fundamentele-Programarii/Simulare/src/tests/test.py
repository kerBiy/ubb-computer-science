from infrastructure.repository import Repository
from domain.entity import Location


class Test:
    def __init__(self, file_name: str) -> None:
        self.__file_name = file_name

    def __test_filter(self) -> None:
        repo = Repository(self.__file_name)
        good_output = [
            Location(11, "str xyz nr 16", "Cluj-Napoca", 500.0, 350.0),
            Location(15, "str xyz nr 6", "Cluj-Napoca", 150.0, 350.0),
        ]

        output = repo.filter(500, "Cluj-Napoca")

        assert good_output == output

    def __test_rent(self) -> None:
        repo = Repository(self.__file_name)
        good_output = 0

        location = repo.rent(18)

        output = 0

        assert good_output == output

    def run_all_tests(self) -> None:
        self.__test_filter()
        self.__test_rent()
        print("All tests are passed")
