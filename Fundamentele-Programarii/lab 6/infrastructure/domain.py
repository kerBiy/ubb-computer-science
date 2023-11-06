def create_expense(apartment: int, value: float, type: str, date: str) -> list:
    # return {"apartment": apartment, "value": value, "type": type, "date": date}
    return [apartment, value, type, date]


def get_apartment(expense: list) -> int:
    return expense[0]


def get_value(expense: list) -> float:
    return expense[1]


def get_type(expense: list) -> str:
    return expense[2]


def get_date(expense: list) -> str:
    return expense[3]
