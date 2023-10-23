from os import system
from datetime import datetime


# /----- Utilities -----/


def clear_screen() -> None:
    system("clear")


def valid_date(date: str) -> bool:
    format = "%Y/%m/%d"
    return datetime.strptime(date, format)


def input_number(prompt: str, function):
    while True:
        try:
            user_input = input(prompt)
            user_input = function(user_input)
            assert user_input >= 0
            return user_input
        except Exception:
            print("\nPlease enter a valid number.")


def input_date(prompt: str) -> str:
    while True:
        try:
            user_input = input(prompt)
            assert valid_date(user_input)
            return user_input
        except Exception:
            print("\nPlease enter a valid date.")


def input_id(prompt: str, expenses: list[dict]) -> int:
    while True:
        try:
            user_input = input(prompt)
            user_input = int(user_input)
            assert 1 <= user_input <= len(expenses)
        except Exception:
            print("\nPlease enter a valid id: ")


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
    apartment = input_number("Enter the apartment number: ", int)
    value = input_number("Enter the expense value: ", float)
    type = input("Enter the expense type: ")
    date = input_date("Enter the expense date(yyyy/mm/dd): ")

    add_expense(expenses, apartment, value, type, date)


def ui_modify_expense(expenses: list[dict]) -> None:
    print_expenses(expenses)

    id = input_id("\nPlease enter the id of the expense you want to modify: ", expenses)
    apartment = input_number("\nEnter the expense apartment: ", int)
    value = input_number("Enter the expense value: ", float)
    type = input("Enter the expense type: ")
    date = input_date("Enter the expense date(yyyy/mm/dd): ")

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
    new_expense = []
    correct_expense = [
        {"apartment": 112, "val": 350.99, "type": "gas", "date": "2020/05/22"}
    ]

    add_expense(new_expense, 112, 350.99, "gas", "2020/05/22")

    assert correct_expense == new_expense


def test_modify_expense() -> None:
    new_expense = [
        {"apartment": 113, "val": 50.98, "type": "gas", "date": "2020/05/20"}
    ]
    correct_expense = [
        {"apartment": 112, "val": 350.99, "type": "gas", "date": "2020/05/22"}
    ]

    id_expense = 1
    modify_expense(new_expense, id_expense, 112, 350.99, "gas", "2020/05/22")

    assert correct_expense == new_expense


# /----- Deleting -----/


def delete_submenu(expenses: list[dict]) -> None:
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
    apartment = input_number(
        "Enter the apartment number you want to delete all the expenses from: ", int
    )

    delete_all_expenses_from_apartment(expenses, apartment)


def ui_delete_consecutive_expenses(expenses: list[dict]) -> None:
    first_apartment = input_number("Enter the first apartment number: ", int)
    second_apartment = input_number("Enter the second apartment number: ", int)

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
    new_expenses = [
        {"apartment": 112, "val": 950.99, "type": "trash", "date": "2021/10/22"},
        {"apartment": 102, "val": 99.99, "type": "light", "date": "2022/05/22"},
        {"apartment": 112, "val": 2020.50, "type": "gas", "date": "2020/05/27"},
        {"apartment": 113, "val": 350.99, "type": "gas", "date": "2020/05/22"},
    ]
    correct_expenses = [
        {"apartment": 102, "val": 99.99, "type": "light", "date": "2022/05/22"},
        {"apartment": 113, "val": 350.99, "type": "gas", "date": "2020/05/22"},
    ]

    delete_all_expenses_from_apartment(new_expenses, 112)

    assert correct_expenses == new_expenses


def test_delete_consecutive_expenses() -> None:
    new_expenses = [
        {"apartment": 112, "val": 950.99, "type": "trash", "date": "2021/10/22"},
        {"apartment": 102, "val": 99.99, "type": "light", "date": "2022/05/22"},
        {"apartment": 112, "val": 2020.50, "type": "gas", "date": "2020/05/27"},
        {"apartment": 113, "val": 350.99, "type": "gas", "date": "2020/05/22"},
    ]
    correct_expenses = [
        {"apartment": 102, "val": 99.99, "type": "light", "date": "2022/05/22"}
    ]

    delete_consecutive_expenses(new_expenses, 105, 115)

    assert correct_expenses == new_expenses


def test_delete_all_expenses_of_the_same_type() -> None:
    new_expenses = [
        {"apartment": 112, "val": 950.99, "type": "trash", "date": "2021/10/22"},
        {"apartment": 102, "val": 99.99, "type": "light", "date": "2022/05/22"},
        {"apartment": 112, "val": 2020.50, "type": "gas", "date": "2020/05/27"},
        {"apartment": 113, "val": 350.99, "type": "gas", "date": "2020/05/22"},
    ]
    correct_expenses = [
        {"apartment": 112, "val": 950.99, "type": "trash", "date": "2021/10/22"},
        {"apartment": 102, "val": 99.99, "type": "light", "date": "2022/05/22"},
    ]

    delete_all_expenses_of_the_same_type(new_expenses, "gas")

    assert correct_expenses == new_expenses


# /----- Main -----/


def option_menu() -> None:
    print("\n\nOPTION MENU:")
    print("Enter 0 for showing the expenses list")
    print("Enter 1 for add menu")
    print("Enter 2 for delete menu")
    print("Enter q for Exiting the program")


def test_functions() -> None:
    test_add_expense()
    test_modify_expense()
    test_delete_all_expenses_from_apartment()
    test_delete_consecutive_expenses()
    test_delete_all_expenses_of_the_same_type()
    print("All tests passed!")


def console_application():
    expenses = []
    options = {
        0: print_expenses,
        1: add_submenu,
        2: delete_submenu,
    }

    while True:
        option_menu()
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
    test_functions()
    console_application()
