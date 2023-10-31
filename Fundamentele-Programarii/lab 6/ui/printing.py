from business.manager import (
    manager_print_total_sum_expenses_of_type,
    manager_print_sorted_apartments_by_type,
    manager_print_total_sum_expenses_of_the_apartment,
)


def ui_print_command(expenses: list[list], cmd: list[str]) -> None:
    if not cmd:
        raise Exception("Invalid command parameters.")

    specific_command = cmd[0]
    cmd = cmd[1:]

    options = {
        "-ts": ui_print_total_sum_expenses_of_type,
        "-st": ui_print_sorted_apartments_by_type,
        "-as": ui_print_total_sum_expenses_of_the_apartment,
    }

    assert specific_command in options.keys(), "Invalid specific command."
    options[specific_command](expenses, cmd)


def ui_print_total_sum_expenses_of_type(expenses: list[list], cmd: list[str]) -> None:
    if len(cmd) != 1:
        raise Exception("Invalid command parameters.")

    type = cmd[0]

    manager_print_total_sum_expenses_of_type(expenses, type)


def ui_print_sorted_apartments_by_type(expenses: list[list], cmd: list[str]) -> None:
    if len(cmd) != 1:
        raise Exception("Invalid command parameters.")

    type = cmd[0]

    manager_print_sorted_apartments_by_type(expenses, type)


def ui_print_total_sum_expenses_of_the_apartment(
    expenses: list[list], cmd: list[str]
) -> None:
    if len(cmd) != 1:
        raise Exception("Invalid command parameters.")

    apartment = int(cmd[0])

    manager_print_total_sum_expenses_of_the_apartment(expenses, apartment)
