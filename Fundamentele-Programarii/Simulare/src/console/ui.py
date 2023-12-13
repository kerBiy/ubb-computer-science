from business.manager import Manager


class Ui:
    def __init__(self, manager: Manager) -> None:
        self.__manager = manager

    def __print_options(self) -> None:
        print("\nOPTIONS MENU")
        print("Press 1 for filtering")
        print("Press 2 for renting")

    def __filter(self) -> None:
        budget = float(input("Enter the budget you have: "))
        city = input("Enter the city you want: ")
        city = city.strip()

        locations = self.__manager.filter(budget, city)

        if not locations:
            raise Exception("There are no such locations.")

        for location in locations:
            print(location)

    def __rent(self) -> None:
        id = int(input("Enter the id of the location: "))

        price = self.__manager.rent(id)

        if not price:
            raise Exception("Location not found.")

        print(f"The price you have to pay is {price}$")

    def run(self) -> None:
        while True:
            self.__print_options()
            option = input("Please enter a number: ")

            try:
                if option == "1":
                    self.__filter()
                elif option == "2":
                    self.__rent()
                elif option == "x":
                    print("Exiting the program...")
                    return
                else:
                    print("Please enter a valid option.")

            except ValueError as ve:
                print(ve)
            except TypeError as te:
                print(te)
            except Exception as e:
                print(e)
