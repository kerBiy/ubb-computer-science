from domain import create_expense
from validator import validate_expense, validate_id
from utils import print_expenses
from functions import *


def manager_print_expenses(expenses: list[dict]) -> None:
    print_expenses(expenses) if expenses else print("Expenses list is empty")


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


def manager_delete_all_expenses_from_apartment(
    expenses: list[dict], apartment: int
) -> None:
    pass


def manager_delete_all_consecutive_expenses(
    expenses: list[dict], first_apartment: int, second_apartment: int
) -> None:
    pass


def manager_delete_all_expenses_of_same_type(expenses: list[dict], type: str) -> None:
    pass
