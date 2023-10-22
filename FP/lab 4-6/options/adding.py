from utils import get_input, clear_screen
from functions import addExpense, modifyExpenseAtApartment


def addMenu(expenses: list[dict]) -> None:
    clear_screen()
    print("Enter 1 for adding an expenses")
    print("Enter 2 for modifying an expense")

    options = {1: add_expense, 2: modify_expense}
    get_input(expenses, options)


def add_expense(expenses: list[dict]) -> None:
    print("Adding an expense:\n")
    apartment = int(input("Enter the apartment number: "))
    value = float(input("Enter the expense value: "))
    type = input("Enter the expense type: ")
    date = input("Enter the expense date(yyyy/mm/dd): ")

    addExpense(expenses, apartment, value, type, date)


def modify_expense(expenses: list[dict]) -> None:
    apartment = int(input("Enter the apartment number you want to modify: "))
    value = float(input("\nEnter the expense value: "))
    type = input("Enter the expense type: ")
    date = input("Enter the expense date(yyyy/mm/dd): ")

    modifyExpenseAtApartment(expenses, apartment, value, type, date)
