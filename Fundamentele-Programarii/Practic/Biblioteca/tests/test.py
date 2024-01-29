from domain.entity import Book


class Test:
    def __init__(self) -> None:
        self.__epsilon = 0.001

    def __domain_tests(self) -> None:
        print("Starting Domain Tests...")

        self.__id = 101
        self.__title = "The Alchemist"
        self.__author = "I don't know"
        self.__year = 1896

        self.__book = Book(self.__id, self.__title, self.__author, self.__year)
        assert self.__book.id == self.__id
        assert self.__book.title == self.__title
        assert self.__book.author == self.__author
        assert abs(self.__book.year - self.__year) < self.__epsilon

        print("Successful Domain Tests")

    def __infrastructure_test(self) -> None:
        print("Starting Infrastructure Tests...")

    def run_all(self) -> None:
        print("Start Testing...")
        self.__domain_tests()
        self.__infrastructure_test()
