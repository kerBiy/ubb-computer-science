from domain.entity import Book


class RepoError(Exception):
    pass


class Repository:
    def __init__(self, file_name: str) -> None:
        self.__file_name = file_name
        self.__items = []
        self.__load_items()

    @property
    def items(self) -> list[Book]:
        return self.__items

    @items.setter
    def items(self, new_list: list[Book]) -> None:
        self.__items = new_list

    def __load_items(self) -> None:
        """
        Loads all the items from the data base and stores them into self.items
        """
        with open(self.__file_name, "r") as file:
            for line in file:
                record = line.strip().split(",")
                book = Book(int(record[0]), record[1], record[2], int(record[3]))
                self.items.append(book)

    def save_items(self) -> None:
        """
        Saves the items stored in self.items to the data base
        """
        with open(self.__file_name, "w") as file:
            for item in self.items:
                new_line = (
                    f"{item.id},{item.title},{item.author},{item.year}\n"
                )
                file.write(new_line)

    def __find_digit(self, digit: int) -> list[Book]:
        """
        Finds all instances where the id has the digit in it
        Returns a list of all instances found
        """

        def contains_digit(number: int) -> bool:
            if number == 0:
                return False
            if number % 10 == digit:
                return True

            return contains_digit(number // 10)

        output = [item for item in self.items if contains_digit(item.id)]
        return output

    def add(self, new_book: Book) -> None:
        """
        Adds a new book in the database
        """
        self.items.append(new_book)
        self.save_items()

    def modify(self, digit: int, new_author: str) -> None:
        """
        Modifies the author of the books that contains the digit in their id
        Raises a RepoError if there are no books that fit the description
        """
        books = self.__find_digit(digit)

        if not books:
            raise RepoError("There are no books with this digit.")

        for book in books:
            book.author = new_author

        self.save_items()
