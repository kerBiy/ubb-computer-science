from validate.validator import already_exists
from infrastructure.domain import get_apartment, get_value, get_type, get_date


# /----- Adding -----/


def add_expense(expenses: list[list], expense: dict) -> None:
    if already_exists(expenses, expense):
        raise Exception("Already exists in the list.")

    expenses.append(expense)


def modify_expense(expenses: list[list], id: int, expense: dict) -> None:
    expenses[id - 1] = expense.copy()


# /----- Deleting -----/


def delete_all_expenses_from_apartment(expenses: list[list], apartment: int) -> None:
    expenses[:] = [
        expense for expense in expenses if get_apartment(expense) != apartment
    ]


def delete_all_consecutive_expenses(
    expenses: list[list], first_apartment: int, second_apartment: int
) -> None:
    expenses[:] = [
        expense
        for expense in expenses
        if not first_apartment <= get_apartment(expense) <= second_apartment
    ]


def delete_all_expenses_of_same_type(expenses: list[list], type: str) -> None:
    expenses[:] = [expense for expense in expenses if get_type(expense) != type]


# /----- Searching -----/


def search_all_expenses_of_type(expenses: list[list], type: str) -> dict[dict]:
    output = {}

    for itr, expense in enumerate(expenses):
        if get_type(expense) == type:
            output[itr] = expense

    return output


# /----- Printing -----/


def print_total_sum_expenses_of_type(expenses: list[list], type: str) -> float:
    return sum(get_value(expense) for expense in expenses if get_type(expense) == type)


# /----- Filtering -----/


def eliminate_all_expenses_lower_than(expenses: list[list], value: float) -> dict[dict]:
    output = {}

    for itr, expense in enumerate(expenses):
        if get_value(expense) >= value:
            output[itr] = expense

    return output


# /----- Undoing -----/


def can_undo(history: list[list[list]]) -> bool:
    return len(history) > 1


def undo_command(expenses: list[list], history: list[list[list]]) -> bool:
    history.pop()
    expenses[:] = history[-1]
