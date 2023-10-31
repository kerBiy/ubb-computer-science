from business.manager import (
    manager_search_all_apartments_with_expenses_higher_than,
    manager_search_all_expenses_of_type,
    manager_search_all_expenses_before_date_bigger_than_value,
)


def ui_search_command(expenses: list[list], cmd: list[str]) -> None:
    if not cmd:
        raise Exception("Invalid command parameters.")

    specific_command = cmd[0]
    cmd = cmd[1:]

    options = {
        "-hv": ui_search_all_apartments_with_expenses_higher_than,
        "-t": ui_search_all_expenses_of_type,
        "-bd": ui_search_all_expenses_before_date_bigger_than_value,
    }

    assert specific_command in options.keys(), "Invalid specific command."
    options[specific_command](expenses, cmd)


def ui_search_all_apartments_with_expenses_higher_than(
    expenses: list[list], cmd: list[str]
) -> None:
    if len(cmd) != 1:
        raise Exception("Invalid command parameters.")

    value = float(cmd[0])

    manager_search_all_apartments_with_expenses_higher_than(expenses, value)


def ui_search_all_expenses_of_type(expenses: list[list], cmd: list[str]) -> None:
    if len(cmd) != 1:
        raise Exception("Invalid command parameters.")

    type = cmd[0]

    manager_search_all_expenses_of_type(expenses, type)


def ui_search_all_expenses_before_date_bigger_than_value(
    expenses: list[list], cmd: list[str]
) -> None:
    if len(cmd) != 2:
        raise Exception("Invalid command parameters.")

    date = cmd[0]
    value = float(cmd[1])

    manager_search_all_expenses_before_date_bigger_than_value(expenses, date, value)
