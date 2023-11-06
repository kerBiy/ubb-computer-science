from validate.validator import (
    validate_expense,
    validate_id,
    validate_apartment,
    validate_value,
    validate_type,
    validate_date,
)
from infrastructure.domain import create_expense
from infrastructure.utils import print_expenses, print_dict, list_to_str
from infrastructure.functions import *


# /----- Adding -----/


def manager_add_expense(
    expenses: list[list], apartment: int, value: float, type: str, date: str
) -> None:
    new_expense = create_expense(apartment, value, type, date)
    validate_expense(new_expense)
    add_expense(expenses, new_expense)


def manager_modify_expense(
    expenses: list[list], id: int, apartment: int, value: float, type: str, date: str
) -> None:
    new_expense = create_expense(apartment, value, type, date)
    validate_expense(new_expense)
    validate_id(expenses, id)
    modify_expense(expenses, id, new_expense)


# /----- Deleting -----/


def manager_delete_all_expenses_from_apartment(
    expenses: list[list], apartment: int
) -> None:
    validate_apartment(apartment)
    delete_all_expenses_from_apartment(expenses, apartment)


def manager_delete_all_consecutive_expenses(
    expenses: list[list], first_apartment: int, second_apartment: int
) -> None:
    validate_apartment(first_apartment)
    validate_apartment(second_apartment)
    delete_all_consecutive_expenses(expenses, first_apartment, second_apartment)


def manager_delete_all_expenses_of_same_type(expenses: list[list], type: str) -> None:
    validate_type(type)
    delete_all_expenses_of_same_type(expenses, type)


# /----- Searching -----/


def manager_search_all_apartments_with_expenses_higher_than(
    expenses: list[list], value: float
) -> None:
    validate_value(value)
    list_apartments = search_all_apartments_with_expenses_higher_than(expenses, value)
    print(
        f"The apartments with expenses higher than {value}$ are: {list_to_str(list_apartments)}"
    )


def manager_search_all_expenses_of_type(expenses: list[list], type: str) -> None:
    validate_type(type)
    final_expenses = search_all_expenses_of_type(expenses, type)
    print(f"The expense of type {type} are:")
    print_dict(final_expenses)


def manager_search_all_expenses_before_date_bigger_than_value(
    expenses: list[list], date: str, value: float
) -> None:
    validate_date(date)
    validate_value(value)
    final_expenses = search_all_expenses_before_date_bigger_than_value(
        expenses, date, value
    )
    print(f"The expenses before {date} higher than {value}$ are:")
    print_dict(final_expenses)


# /----- Printing -----/


def manager_print_total_sum_expenses_of_type(expenses: list[list], type: str) -> None:
    validate_type(type)
    sum_of_expenses = print_total_sum_expenses_of_type(expenses, type)
    print(f"The sum of all expenses of type {type} is: {sum_of_expenses}")


def manager_print_sorted_apartments_by_type(expenses: list[list], type: str) -> None:
    validate_type(type)
    list_apartments = print_sorted_apartments_by_type(expenses, type)
    print(
        f"The apartments sorted in descending order by type {type} are: {list_to_str(list_apartments)}"
    )


def manager_print_total_sum_expenses_of_the_apartment(
    expenses: list[list], apartment: int
) -> None:
    validate_apartment(apartment)
    sum_of_expenses = print_total_sum_expenses_of_the_apartment(expenses, apartment)
    print(f"The sum of all expenses from {apartment} apartment is: {sum_of_expenses}")


# /----- Filtering -----/


def manager_eliminate_all_expenses_of_type(
    expenses: list[list], type: str
) -> None:
    validate_type(type)
    filtered_list = eliminate_all_expenses_of_type(expenses, type)
    print(f"The filtrated expenses without the type {type} are:")
    print_dict(filtered_list)


def manager_eliminate_all_expenses_lower_than(
    expenses: list[list], value: float
) -> None:
    validate_value(value)
    filtered_list = eliminate_all_expenses_lower_than(expenses, value)
    print(f"The filtrated expenses without an expense lower than {value}$ is:")
    print_dict(filtered_list)
