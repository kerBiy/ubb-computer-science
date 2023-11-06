from validate.validator import already_exists
from infrastructure.domain import get_apartment, get_value, get_type, get_date


# /----- Adding -----/


def add_expense(expenses: list[list], expense: list) -> None:
    if already_exists(expenses, expense):
        raise Exception("Already exists in the list.")

    expenses.append(expense)


def modify_expense(expenses: list[list], id: int, expense: list) -> None:
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


def search_all_apartments_with_expenses_higher_than(
    expenses: list[list], value: float
) -> list[int]:
    apartments_expenses = {}

    for expense in expenses:
        apartments_expenses[get_apartment(expense)] = apartments_expenses.get(
            get_apartment(expense), 0
        ) + get_value(expense)

    return sorted(
        [key for key in apartments_expenses if apartments_expenses[key] >= value]
    )


def search_all_expenses_of_type(expenses: list[list], type: str) -> dict[list]:
    output = {}

    for itr, expense in enumerate(expenses):
        if get_type(expense) == type:
            output[itr] = expense

    return output


def search_all_expenses_before_date_bigger_than_value(
    expenses: list[list], date: str, value: float
) -> dict[list]:
    output = {}

    for itr, expense in enumerate(expenses):
        if get_date(expense) < date and get_value(expense) >= value:
            output[itr] = expense

    return output


# /----- Printing -----/


def print_total_sum_expenses_of_type(expenses: list[list], type: str) -> float:
    return sum(get_value(expense) for expense in expenses if get_type(expense) == type)


def print_sorted_apartments_by_type(expenses: list[list], type: str) -> list[int]:
    val_map = {}

    for expense in expenses:
        if get_type(expense) == type:
            val_map[get_apartment(expense)] = val_map.get(
                get_apartment(expense), 0
            ) + get_value(expense)

    return sorted(val_map, key=lambda k: val_map[k], reverse=True)


def print_total_sum_expenses_of_the_apartment(
    expenses: list[list], apartment: int
) -> float:
    return sum(
        get_value(expense)
        for expense in expenses
        if get_apartment(expense) == apartment
    )


# /----- Filtering -----/


def eliminate_all_expenses_of_type(expenses: list[list], type: str) -> dict[list]:
    output = {}

    for itr, expense in enumerate(expenses):
        if get_type(expense) != type:
            output[itr] = expense

    return output


def eliminate_all_expenses_lower_than(expenses: list[list], value: float) -> dict[list]:
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
