from utils import (
    get_input_for_submenu,
    clear_screen,
    input_number,
)
from functions import (
    delete_all_expenses_from_apartment,
    delete_consecutive_expenses,
    delete_all_expenses_of_the_same_type,
)


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
