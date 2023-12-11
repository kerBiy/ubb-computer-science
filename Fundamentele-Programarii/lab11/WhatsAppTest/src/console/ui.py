from os import system
from business.manager import Manager


class Ui:
    def __init__(self, furniture_manager: Manager) -> None:
        self.__manager = furniture_manager
        self.__options = {1: self.__search, 2: self.__buy}

    def __print_options(self) -> None:
        print("\nOPTIONS LIST:")
        print("Enter 1 for searching")
        print("Enter 2 for buying")

    def __search(self) -> None:
        object_type = input("Enter the object type you want: ")
        object_list = self.__manager.search(object_type)

        if not object_list:
            print(f"There isn't a furniture of this type.")
            return

        for obj in object_list:
            print(obj)

    def __buy(self) -> None:
        try:
            code = input("Enter the id of the furniture you want to buy: ")
            count = int(input("Enter how many pieces of this furniture you want: "))
            self.__manager.buy(code, count)
            print(f"You have bought {count} pieces of this furniture.")
        except ValueError:
            print("That's not a number.")

    def run(self) -> None:
        if not self.__manager.validate_file_items():
            print("The file has corrupted elements.")
            return

        while True:
            self.__print_options()
            option = input("\nEnter a number: ")
            system("clear")

            if option == "q":
                print("Exiting the program...")
                return

            try:
                option = int(option)
                assert option in self.__options, "This option is not yet implemented."
                self.__options[option]()
            except ValueError as ve:
                print(ve)
            except TypeError as te:
                print(te)
            except Exception as ex:
                print(ex)
