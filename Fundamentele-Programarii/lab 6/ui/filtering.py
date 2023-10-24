from utils import (
    get_input_for_submenu,
    clear_screen,
    input_number,
)
from functions import (
    eliminate_all_expenses_lower_than,
    eliminate_all_expenses_of_same_type,
)


def filter_submenu(expenses: list[dict]) -> None:
    clear_screen()
    print("Enter 2 to eliminate all expenses lower than a value")

    options = {
        1: ui_eliminate_all_expenses_of_same_type,
        2: ui_eliminate_all_expenses_lower_than,
    }

    get_input_for_submenu(expenses, options)


def ui_eliminate_all_expenses_of_same_type(expenses: list[dict]) -> None:
    type = input("Enter the type you want to eliminate: ")
    eliminate_all_expenses_of_same_type(expenses, type)


def ui_eliminate_all_expenses_lower_than(expenses: list[dict]) -> None:
    val = input_number("Enter the value to cut all the smaller elements: ", float)
    eliminate_all_expenses_lower_than(expenses, val)
