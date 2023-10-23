from utils import get_input, clear_screen
from functions import (
    allApartmentsWithExpensesHigherThan,
    allExpensesOfType,
    allExpensesBeforeDateBiggerThanVal,
)


def searchMenu(expenses: list[dict]) -> None:
    clear_screen()
    print("Enter 1 to search the expenses higher than a value")
    print("Enter 2 to search all expenses of a single type")
    print("Enter 3 to search all the expenses before date")

    options = {
        1: search_expenses_higher,
        2: search_expenses_of_type,
        3: search_expenses_before_date,
    }

    get_input(expenses, options)


def search_expenses_higher(expenses: list[dict]) -> None:
    val = float(input("Enter the expense value: "))
    apartments_list = allApartmentsWithExpensesHigherThan(expenses, val)

    print(
        f"\nAll apartments that have expenses higher than {val} are:\n {apartments_list}"
    )


def search_expenses_of_type(expenses: list[dict]) -> None:
    type = input("Enter the expense type: ")
    expenses_list = allExpensesOfType(expenses, type)

    print(f"\nAll expenses of type: {type} are:\n {expenses_list}")


def search_expenses_before_date(expenses: list[dict]) -> None:
    date = input("Enter the expense date(yyyy/mm/dd): ")
    val = float(input("Enter the expense value: "))
    expenses_list = allExpensesBeforeDateBiggerThanVal(expenses, date, val)

    print(f"\nAll expenses of type: {type} are:\n {expenses_list}")
