from sys import exit
from tabulate import tabulate
from business.service import Service, ValidError


class Console:
    def __init__(self, service: Service) -> None:
        self.__service = service

        self.__options = {
            "1": self.__delete_show,
            "2": self.__modify_show,
            "3": self.__random_show,
            "x": self.__exit_app,
        }

    def __print_menu(self) -> None:
        print("\nOPTION MENU")
        print("Press 1 to delete a tv show")
        print("Press 2 to modify an existing tv show")
        print("Press 3 to generate random tv shows")
        print("Press x to exit the app")

    def __delete_show(self) -> None:
        name = input("Enter the name: ")
        type = input("Enter the type: ")

        self.__service.delete(name, type)

    def __modify_show(self) -> None:
        try:
            name = input("Enter the name: ")
            type = input("Enter the type: ")
            new_screen_time = int(input("Enter the new screen time in hours: "))
            new_description = input("Enter the new description: ")

            self.__service.modify(name, type, new_screen_time, new_description)
        except ValueError:
            print("Value Error: The screen time value is not representative.")

    def __random_show(self) -> None:
        try:
            start = int(input("Enter the beginning hour: "))
            end = int(input("Enter the ending hour: "))

            schedule = self.__service.random(start, end)

            print(
                "\n",
                tabulate(schedule, headers=["Hour", "Name", "Type", "Description"]),
            )
        except ValidError as ve:
            print("Validation Error:", ve)

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
            except Exception as ex:
                print("Error:", ex)
