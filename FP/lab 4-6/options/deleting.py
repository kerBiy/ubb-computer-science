from utils import get_input, clear_screen
from functions import (
    deleteAllExpensesFrom,
    deleteConsecutiveExpensesFrom,
    deleteExpensesOfType,
)


def deleteMenu(expenses: list[dict]) -> None:
    clear_screen()
    print("Enter 1 for dealiting all the expenses of one apartment")
    print("Enter 2 for dealiting all the consecutive apartments expenses")
    print("Enter 3 for dealiting all the expenses of one type")

    options = {
        1: delete_expenses_apartment,
        2: delete_consecutive,
        3: delete_expenses_type,
    }

    get_input(expenses, options)


def delete_expenses_apartment(expenses: list[dict]) -> None:
    apartment = int(
        input("Enter the apartment number you want to delete all the expenses from: ")
    )
    deleteAllExpensesFrom(expenses, apartment)


def delete_consecutive(expenses: list[dict]) -> None:
    first_apartment = int(input("Enter the first apartment number: "))
    second_apartment = int(input("Enter the second apartment number: "))

    deleteConsecutiveExpensesFrom(expenses, first_apartment, second_apartment)


def delete_expenses_type(expenses: list[dict]) -> None:
    type = input("Enter the expense type you want to delete: ")
    deleteExpensesOfType(expenses, type)
