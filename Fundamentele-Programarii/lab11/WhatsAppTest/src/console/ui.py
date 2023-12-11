from os import system
from business.manager import Manager


class Ui:
    def __init__(self, furniture_manager: Manager) -> None:
        self.__manager = furniture_manager

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
        while True:
            self.__print_options()
            option = input("\nEnter a number: ")
            system("clear")

            if option == "1":
                self.__search()
            elif option == "2":
                self.__buy()
            elif option == "q":
                print("Exiting the program...")
                break
            else:
                print("This option is not yet implemented.")
