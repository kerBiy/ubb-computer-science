from utils import get_input, clear_screen
from functions import eliminateAllExpensesLowerThan


def filterMenu(expenses: list[dict]) -> None:
    clear_screen()
    print("Enter 2 to eliminate all expenses lower than a value")

    options = {2: elimin_lower_val}

    get_input(expenses, options)


def elimin_lower_val(expenses: list[dict]) -> None:
    val = float(input("Enter the value to cut all the smaller elements: "))
    eliminateAllExpensesLowerThan(expenses, val)
