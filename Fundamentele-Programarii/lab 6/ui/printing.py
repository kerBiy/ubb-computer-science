from utils import get_input, clear_screen
from functions import sumExpensesOfType, sortApartmentsByType, totalExpensesForApartment


def printMenu(expenses: list[dict]) -> None:
    clear_screen()
    print("Enter 1 to print the sum of all the expenses of the same type")
    print("Enter 2 to print the apartments sorted by type")
    print("Enter 3 to print the sum of all expenses for one single apartment")

    options = {
        1: sum_expenses_type,
        2: sort_by_type,
        3: sum_expenses_apartment,
    }

    get_input(expenses, options)


def sum_expenses_type(expenses: list[dict]) -> None:
    type = input("Enter the type to know the total expense: ")
    total_expense = sumExpensesOfType(expenses, type)

    print(f"\nThe total sum of expenses that are the type: {type} is: {total_expense}")


def sort_by_type(expenses: list[dict]) -> None:
    type = input("Enter the type to know to sort the list by: ")
    sorted_expenses = sortApartmentsByType(expenses, type)

    print(f"\nThe sorted apartments with the type: {type} are: {sorted_expenses}")


def sum_expenses_apartment(expenses: list[dict]) -> None:
    apartment = int(input("Enter the apartment number to find the total expenses: "))
    total_expense = totalExpensesForApartment(expenses, apartment)

    print(
        f"\nThe total sum of expenses for the apartment: {apartment} is: {total_expense}"
    )
