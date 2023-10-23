from os import system
from datetime import datetime


# /----- Utilities -----/


def clear_screen() -> None:
    system("clear")


def valid_date(date: str) -> bool:
    format = "%Y/%m/%d"
    return datetime.strptime(date, format)


def input_number(function, prompt: str):
    while True:
        try:
            user_input = input(prompt)
            user_input = function(user_input)
            return user_input
        except ValueError():
            print("\nPlease enter a valid number.")


def input_date(prompt: str) -> str:
    while True:
        try:
            user_input = input(prompt)
            assert valid_date(user_input)
        except Exception:
            print("\nPlease enter a valid date.")


def get_input_for_submenu(expenses: list[dict], options: dict) -> None:
    print("Enter b to go back")
    user_input = input("\nEnter your option again: ")
    clear_screen()

    if user_input == "b":
        return

    user_input = int(user_input)
    options[user_input](expenses)


def print_expenses(expenses: list[dict]) -> None:
    print("EXPENSES LIST:")
    for index, expense in enumerate(expenses):
        print(
            f"{index + 1}. Apartment: {expense['apartment']}, Value: {expense['val']}, Type: {expense['type']}, Date: {expense['date']}"
        )


# /----- Adding -----/


def add_submenu(expenses: list[dict]) -> None:
    clear_screen()
    print("Enter 1 for adding an expenses")
    print("Enter 2 for modifying an expense")

    options = {1: ui_add_expense, 2: ui_modify_expense}
    get_input_for_submenu(expenses, options)


def ui_add_expense(expenses: list[dict]) -> None:
    print("Adding an expense:\n")
    apartment = int(input("Enter the apartment number: "))
    value = float(input("Enter the expense value: "))
    type = input("Enter the expense type: ")
    date = input("Enter the expense date(yyyy/mm/dd): ")

    add_expense(expenses, apartment, value, type, date)


def ui_modify_expense(expenses: list[dict]) -> None:
    print_expenses(expenses)

    id = int(input("\nPlease enter the id of the expense you want to modify: "))

    while id > len(expenses) or id <= 0:
        id = int(input("Please enter a valid id: "))

    apartment = int(input("\nEnter the expense apartment: "))
    value = float(input("Enter the expense value: "))
    type = input("Enter the expense type: ")
    date = input("Enter the expense date(yyyy/mm/dd): ")

    modify_expense(expenses, id, apartment, value, type, date)


def add_expense(
    expenses: list[dict], apartment: int, val: float, type: str, date: str
) -> None:
    expenses.append({"apartment": apartment, "val": val, "type": type, "date": date})


def modify_expense(
    expenses: list[dict], id: int, apartment: int, val: float, type: str, date: str
) -> None:
    id -= 1
    expenses[id]["apartment"] = apartment
    expenses[id]["val"] = val
    expenses[id]["type"] = type
    expenses[id]["date"] = date


def test_add_expense() -> None:
    pass


def test_modify_expense() -> None:
    pass


# /----- Deleting -----/


def deleteMenu(expenses: list[dict]) -> None:
    clear_screen()
    print("Enter 1 for deleting all the expenses of one apartment")
    print("Enter 2 for deleting all the consecutive apartments expenses")
    print("Enter 3 for deleting all the expenses of one type")

    options = {
        1: ui_delete_all_expenses_from_apartment,
        2: ui_delete_consecutive_expenses,
        3: ui_delete_all_expenses_of_the_same_type,
    }

    get_input_for_submenu(expenses, options)


def ui_delete_all_expenses_from_apartment(expenses: list[dict]) -> None:
    apartment = int(
        input("Enter the apartment number you want to delete all the expenses from: ")
    )
    delete_all_expenses_from_apartment(expenses, apartment)


def ui_delete_consecutive_expenses(expenses: list[dict]) -> None:
    first_apartment = int(input("Enter the first apartment number: "))
    second_apartment = int(input("Enter the second apartment number: "))

    delete_consecutive_expenses(expenses, first_apartment, second_apartment)


def ui_delete_all_expenses_of_the_same_type(expenses: list[dict]) -> None:
    type = input("Enter the expense type you want to delete: ")
    delete_all_expenses_of_the_same_type(expenses, type)


def delete_all_expenses_from_apartment(expenses: list[dict], apartment: int) -> None:
    expenses[:] = [expense for expense in expenses if expense["apartment"] != apartment]


def delete_consecutive_expenses(
    expenses: list[dict], apartment_start: int, apartment_end: int
) -> None:
    expenses[:] = [
        expense
        for expense in expenses
        if not apartment_start <= expense["apartment"] <= apartment_end
    ]


def delete_all_expenses_of_the_same_type(expenses: list[dict], type: str) -> None:
    expenses[:] = [expense for expense in expenses if expense["type"] != type]


def test_delete_all_expenses_from_apartment() -> None:
    pass


def test_delete_consecutive_expenses() -> None:
    pass


def test_delete_all_expenses_of_the_same_type() -> None:
    pass


# /----- Main -----/


def mainMenu() -> None:
    print("\n\nOPTION MENU:")
    print("Enter 0 for showing the expenses list")
    print("Enter 1 for add menu")
    print("Enter 2 for delete menu")
    print("Enter q for Exiting the program")


def testFunction() -> None:
    test_add_expense()
    test_modify_expense()
    test_delete_all_expenses_from_apartment()
    test_delete_consecutive_expenses()
    test_delete_all_expenses_of_the_same_type()


def main():
    expenses = []
    options = {
        0: print_expenses,
        1: add_submenu,
        2: deleteMenu,
    }

    while True:
        mainMenu()
        user_input = input("\nEnter an option: ")
        clear_screen()

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
    testFunction()
    main()
