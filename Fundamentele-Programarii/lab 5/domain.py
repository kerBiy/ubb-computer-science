def create_expense(apartment: int, value: float, type: str, date: str) -> dict:
    return {"apartment": apartment, "value": value, "type": type, "date": date}


def get_apartment(expense: dict) -> int:
    return expense["apartment"]


def set_apartment(expense: dict, val: int) -> None:
    expense["apartment"] = val


def get_value(expense: dict) -> float:
    return expense["value"]


def set_value(expense: dict, val: float) -> None:
    expense["value"] = val


def get_type(expense: dict) -> str:
    return expense["type"]


def set_type(expense: dict, val: str) -> None:
    expense["type"] = val


def get_date(expense: dict) -> str:
    return expense["date"]


def set_date(expense: dict, val: str) -> None:
    expense["date"] = val


def is_equal(first_expense: dict, second_expense: dict) -> bool:
    return first_expense == second_expense
