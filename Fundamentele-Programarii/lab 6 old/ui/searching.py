from utils import (
    get_input_for_submenu,
    clear_screen,
    input_number,
    input_date,
)
from functions import (
    search_all_apartments_with_expenses_higher_than,
    search_all_expenses_of_type,
    search_all_expenses_before_date_bigger_than_value,
)


def search_submenu(expenses: list[dict]) -> None:
    clear_screen()
    print("Enter 1 to search all apartments with expenses higher than a val")
    print("Enter 2 to search all expenses of a single type")
    print("Enter 3 to search all the expenses before date")

    options = {
        1: ui_search_all_apartments_with_expenses_higher_than,
        2: ui_search_all_expenses_of_type,
        3: ui_search_all_expenses_before_date_bigger_than_value,
    }

    get_input_for_submenu(expenses, options)


def ui_search_all_apartments_with_expenses_higher_than(expenses: list[dict]) -> None:
    val = input_number("Enter the expense value: ", float)
    apartments_list = search_all_apartments_with_expenses_higher_than(expenses, val)

    print(
        f"\nAll apartments that have expenses higher than {val} are:\n {apartments_list}"
    )


def ui_search_all_expenses_of_type(expenses: list[dict]) -> None:
    type = input("Enter the expense type: ")
    expenses_list = search_all_expenses_of_type(expenses, type)

    print(f"\nAll expenses of type: {type} are:\n {expenses_list}")


def ui_search_all_expenses_before_date_bigger_than_value(expenses: list[dict]) -> None:
    date = input_date("Enter the expense date(yyyy/mm/dd): ")
    val = input_number("Enter the expense value: ", float)
    expenses_list = search_all_expenses_before_date_bigger_than_value(
        expenses, date, val
    )

    print(f"\nAll expenses of type: {type} are:\n {expenses_list}")