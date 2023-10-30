from domain import create_expense
from validator import validate_expense
from functions import *


def manager_add_expense(
    expenses: list[dict], apartment: int, value: float, type: str, date: str
) -> None:
    new_expense = create_expense(apartment, value, type, date)
    validate_expense(new_expense)
    add_expense(expenses, new_expense)
