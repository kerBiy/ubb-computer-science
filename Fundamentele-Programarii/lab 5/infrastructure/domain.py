def create_expense(apartment: int, value: float, type: str, date: str) -> dict:
    return {"apartment": apartment, "value": value, "type": type, "date": date}


def get_apartment(expense: dict) -> int:
    return expense["apartment"]


def get_value(expense: dict) -> float:
    return expense["value"]


def get_type(expense: dict) -> str:
    return expense["type"]


def get_date(expense: dict) -> str:
    return expense["date"]


def is_equal(first_expense: dict, second_expense: dict) -> bool:
    return first_expense == second_expense
