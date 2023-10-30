from domain import create_expense
from validator import (
    validate_expense,
    validate_id,
    validate_apartment,
    validate_value,
    validate_type,
    validate_date,
)
from utils import print_expenses, print_dict
from functions import *


def manager_print_expenses(expenses: list[dict]) -> None:
    print_expenses(expenses) if expenses else print("Expenses list is empty")


# /----- Adding -----/


def manager_add_expense(
    expenses: list[dict], apartment: int, value: float, type: str, date: str
) -> None:
    new_expense = create_expense(apartment, value, type, date)
    validate_expense(new_expense)
    add_expense(expenses, new_expense)


def manager_modify_expense(
    expenses: list[dict], id: int, apartment: int, value: float, type: str, date: str
) -> None:
    new_expense = create_expense(apartment, value, type, date)
    validate_expense(new_expense)
    validate_id(expenses, id)
    modify_expense(expenses, id, new_expense)


# /----- Deleting -----/


def manager_delete_all_expenses_from_apartment(
    expenses: list[dict], apartment: int
) -> None:
    validate_apartment(apartment)
    delete_all_expenses_from_apartment(expenses, apartment)


def manager_delete_all_consecutive_expenses(
    expenses: list[dict], first_apartment: int, second_apartment: int
) -> None:
    validate_apartment(first_apartment)
    validate_apartment(second_apartment)
    delete_all_consecutive_expenses(expenses, first_apartment, second_apartment)


def manager_delete_all_expenses_of_same_type(expenses: list[dict], type: str) -> None:
    validate_type(type)
    delete_all_expenses_of_same_type(expenses, type)


# /----- Searching -----/


def manager_search_all_expenses_of_type(expenses: list[dict], type: str) -> dict[dict]:
    validate_type(type)
    final_expenses = search_all_expenses_of_type(expenses, type)
    print_dict(final_expenses)


# /----- Printing -----/


def manager_print_total_sum_expenses_of_type(
    expenses: list[dict], type: str
) -> dict[dict]:
    validate_type(type)
    sum_of_expenses = print_total_sum_expenses_of_type(expenses, type)
    print(f"The sum of all expenses of type {type} is: {sum_of_expenses}")
