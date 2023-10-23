from os import system
from utils import printExpenses
from options.adding import addMenu
from options.deleting import deleteMenu
from options.searching import searchMenu
from options.printing import printMenu
from options.filtering import filterMenu


def mainMenu() -> None:
    print("\n\nOPTION MENU:")
    print("Enter 0 for showing the expenses list")
    print("Enter 1 for add menu")
    print("Enter 2 for delete menu")
    print("Enter 3 for search menu")
    print("Enter 4 for print menu")
    print("Enter 5 for filter menu")
    print("Enter z for Undo")
    print("Enter q for Exiting the program")


# WOOOW


def main():
    expenses = []
    options = {
        0: printExpenses,
        1: addMenu,
        2: deleteMenu,
        3: searchMenu,
        4: printMenu,
        5: filterMenu,
    }

    while True:
        mainMenu()
        user_input = input("\nEnter an option: ")
        system("clear")

        if user_input == "q":
            print("Exiting the program...")
            break

        try:
            user_input = int(user_input)
            options[user_input](expenses)
        except ValueError:
            print("Invalid input.")
        except KeyError:
            print("This option is not yet implemented.")


if __name__ == "__main__":
    main()
