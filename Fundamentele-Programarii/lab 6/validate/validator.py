from datetime import datetime
from infrastructure.domain import (
    is_equal,
    get_apartment,
    get_value,
    get_type,
    get_date,
)


def validate_expense(expense: list) -> None:
    error = ""

    if not validate_apartment(get_apartment(expense)):
        error += "Invalid apartment number.\n"
    if not validate_value(get_value(expense)):
        error += "Invalid expense value.\n"
    if not validate_type(get_type(expense)):
        error += "Invalid expense type.\n"
    if not validate_date(get_date(expense)):
        error += "Invalid expense date.\n"

    if error:
        raise ValueError(error[: len(error) - 2])


def validate_id(expenses: list[list], id: int) -> bool:
    return 1 <= id <= len(expenses)


def validate_apartment(apartment: int) -> bool:
    return 0 <= apartment <= 9999


def validate_value(value: float) -> bool:
    return 0 <= value <= 99999


def validate_type(type: str) -> bool:
    return type in [
        "gas",
        "trash",
        "telephone",
        "repairs",
        "electricity",
        "water",
        "renovation",
        "light",
    ]


def validate_date(date: str) -> bool:
    format = "%Y/%m/%d"

    try:
        output = datetime.strptime(date, format)
    except ValueError:
        return False

    return True


def already_exists(expenses: list[list], new_expense: dict) -> bool:
    for expense in expenses:
        if is_equal(expense, new_expense):
            return True
    return False
