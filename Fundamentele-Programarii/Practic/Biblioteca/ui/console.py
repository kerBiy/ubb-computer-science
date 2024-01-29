from business.service import Service, ServiceError


class Console:
    def __init__(self, service: Service) -> None:
        self.__service = service

        self.__options = {
            "1": self.__add_book,
            "2": self.__modify_book,
            "z": self.__undo,
            "x": self.__exit_app,
        }

    def __print_menu(self) -> None:
        print("\nOPTION MENU")
        print("Press 1 to add a book")
        print("Press 2 to modify an existing book")
        print("Press z to undo")
        print("Press x to exit the app")

    def __add_book(self) -> None:
        try:
            id = int(input("Enter the id: "))
            title = input("Enter the title: ")
            author = input("Enter the author: ")
            year = int(input("Enter the year: "))
            price = float(input("Enter the price: "))

            self.__service.add_book(id, title, author, year, price)
        except ValueError:
            print("Value Error: Next time enter a fucking number.")

    def __modify_book(self) -> None:
        try:
            digit = int(input("Enter a digit: "))
            new_author = input("Enter the new author: ")

            self.__service.modify_book(digit, new_author)
        except ValueError:
            print("Value Error: Next time enter a fucking number.")

    def __undo(self) -> None:
        try:
            self.__service.undo_command()
            print("Undoing the last operation...")
        except ServiceError as se:
            print(se)

    def __exit_app(self) -> None:
        print("Exiting the program...")
        exit(0)

    def run(self) -> None:
        while True:
            self.__print_menu()
            option = input("\n>>> ")

            try:
                assert option in self.__options, "This option is not yet implemented."

                self.__options[option]()
                self.__service.update_history()
            except Exception as ex:
                print("Error:", ex)
