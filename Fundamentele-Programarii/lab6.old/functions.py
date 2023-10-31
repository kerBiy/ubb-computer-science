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


def search_all_apartments_with_expenses_higher_than(
    expenses: list[dict], val: float
) -> list[int]:
    apartments_expenses = {}

    for expense in expenses:
        apartments_expenses[expense["apartment"]] = (
            apartments_expenses.get(expense["apartment"], 0) + expense["val"]
        )

    return [key for key in apartments_expenses if apartments_expenses[key] >= val]


def search_all_expenses_of_type(expenses: list[dict], type: str) -> list[dict]:
    return [expense for expense in expenses if expense["type"] == type]


def search_all_expenses_before_date_bigger_than_value(
    expenses: list[dict], date: str, val: float
) -> list[dict]:
    return [
        expense
        for expense in expenses
        if expense["date"] < date and expense["val"] > val
    ]


# /----- Printing -----/


def print_total_sum_expenses_of_type(expenses: list[dict], type: str) -> float:
    return sum(expense["val"] for expense in expenses if expense["type"] == type)


def print_sorted_apartments_by_type(expenses: list[dict], type: str) -> list[int]:
    val_map = {}

    for expense in expenses:
        if expense["type"] == type:
            val_map[expense["apartment"]] = (
                val_map.get(expense["apartment"], 0) + expense["val"]
            )

    return sorted(val_map, key=lambda x, y: x["val"] > y["val"])


def print_total_sum_expenses_of_the_apartment(
    expenses: list[dict], apartment: int
) -> float:
    return sum(
        expense["val"] for expense in expenses if expense["apartment"] == apartment
    )


# /----- Filtering -----/


def eliminate_all_expenses_of_same_type(expenses: list[dict], type: str) -> None:
    expenses[:] = [expense for expense in expenses if expense["type"] != type]


def eliminate_all_expenses_lower_than(expenses: list[dict], val: float) -> None:
    expenses[:] = [expense for expense in expenses if expense["val"] > val]


# /----- Undoing -----/


def can_undo(history: list[list[dict]]) -> bool:
    return len(history) > 1


def undo_command(expenses: list[dict], history: list[list[dict]]) -> bool:
    history.pop()
    expenses[:] = history[-1]
