from business.service import Service


class Ui:
    def __init__(self, service: Service) -> None:
        self.__service = service

        self.__options = {
            "1": self.__add_piece,
            "2": self.__modify_piece,
            "3": self.__random_piece,
        }

    def __print_menu(self):
        print("\nOPTION MENU")
        print("Press 1 to add a new theatrical piece")
        print("Press 2 to modify an existing theatrical piece")
        print("Press 3 to generate random theatrical pieces")
        print("Press x to exit the app")

    def __add_piece(self) -> None:
        name = input("Enter the name: ")
        director = input("Enter the director: ")
        genera = input("Enter the genera: ")
        screen_time = int(input("Enter the screen time in minutes: "))

        self.__service.add(name, director, genera, screen_time)

    def __modify_piece(self) -> None:
        name = input("Enter the name: ")
        director = input("Enter the director: ")
        new_genera = input("Enter the new genera: ")
        new_screen_time = int(input("Enter the new screen time in minutes: "))

        self.__service.modify(name, director, new_genera, new_screen_time)

    def __random_piece(self) -> None:
        number = int(input("Enter the number of pieces you want to be generated: "))

        theatrical_pieces = self.__service.generate(number)

        for piece in theatrical_pieces:
            print(piece)

    def run(self) -> None:
        while True:
            self.__print_menu()
            option = input("\n>>> ")

            if option == "exit":
                print("Exiting the program...")
                break

            try:
                assert (
                    option in self.__options.keys()
                ), "This option is not yet implemented."

                self.__options[option]()
            except Exception as ex:
                print(ex)
