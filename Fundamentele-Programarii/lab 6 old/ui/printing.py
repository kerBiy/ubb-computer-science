from utils import (
    get_input_for_submenu,
    clear_screen,
)
from functions import (
    print_total_sum_expenses_of_type,
    print_sorted_apartments_by_type,
    print_total_sum_expenses_of_the_apartment,
)


def print_submenu(expenses: list[dict]) -> None:
    clear_screen()
    print("Enter 1 to print the sum of all the expenses of the same type")
    print("Enter 2 to print the apartments sorted in descending order by type")
    print("Enter 3 to print the sum of all expenses for one single apartment")

    options = {
        1: ui_print_total_sum_expenses_of_type,
        2: ui_print_sorted_apartments_by_type,
        3: ui_print_total_sum_expenses_of_the_apartment,
    }

    get_input_for_submenu(expenses, options)


def ui_print_total_sum_expenses_of_type(expenses: list[dict]) -> None:
    type = input("Enter the type to know the total expense: ")
    total_expense = print_total_sum_expenses_of_type(expenses, type)

    print(f"\nThe total sum of expenses that are the type: {type} is: {total_expense}")


def ui_print_sorted_apartments_by_type(expenses: list[dict]) -> None:
    type = input("Enter the type to know to sort the list by: ")
    sorted_expenses = print_sorted_apartments_by_type(expenses, type)

    print(f"\nThe sorted apartments with the type: {type} are: {sorted_expenses}")


def ui_print_total_sum_expenses_of_the_apartment(expenses: list[dict]) -> None:
    apartment = int(input("Enter the apartment number to find the total expenses: "))
    total_expense = print_total_sum_expenses_of_the_apartment(expenses, apartment)

    print(
        f"\nThe total sum of expenses for the apartment: {apartment} is: {total_expense}"
    )
