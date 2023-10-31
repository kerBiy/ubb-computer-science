from functions import add_expense, modify_expense
from utils import (
    get_input_for_submenu,
    clear_screen,
    print_expenses,
    input_number,
    input_date,
    input_id,
)


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
    if expenses:
        print_expenses(expenses)

        id = input_id(
            "\nPlease enter the id of the expense you want to modify: ", expenses
        )
        apartment = input_number("\nEnter the expense apartment: ", int)
        value = input_number("Enter the expense value: ", float)
        type = input("Enter the expense type: ")
        date = input_date("Enter the expense date(yyyy/mm/dd): ")

        modify_expense(expenses, id, apartment, value, type, date)

    else:
        print("There are no expenses to modify.")
