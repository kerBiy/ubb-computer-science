# /----- Adding -----/


def add_expense(
    expenses: list[dict], apartment: int, val: float, type: str, date: str
) -> None:
    expenses.append({"apartment": apartment, "val": val, "type": type, "date": date})


def modify_expense(
    expenses: list[dict], id: int, apartment: int, val: float, type: str, date: str
) -> None:
    id -= 1
    expenses[id]["apartment"] = apartment
    expenses[id]["val"] = val
    expenses[id]["type"] = type
    expenses[id]["date"] = date


# /----- Deleting -----/


def delete_all_expenses_from_apartment(expenses: list[dict], apartment: int) -> None:
    expenses[:] = [expense for expense in expenses if expense["apartment"] != apartment]


def delete_consecutive_expenses(
    expenses: list[dict], apartment_start: int, apartment_end: int
) -> None:
    expenses[:] = [
        expense
        for expense in expenses
        if not apartment_start <= expense["apartment"] <= apartment_end
    ]


def delete_all_expenses_of_the_same_type(expenses: list[dict], type: str) -> None:
    expenses[:] = [expense for expense in expenses if expense["type"] != type]


# /----- Searching -----/
