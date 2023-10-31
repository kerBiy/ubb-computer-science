from business.manager import (
    manager_eliminate_all_expenses_of_same_type,
    manager_eliminate_all_expenses_lower_than,
)


def ui_filter_command(expenses: list[list], cmd: list[str]) -> None:
    if not cmd:
        raise Exception("Invalid command parameters.")

    specific_command = cmd[0]
    cmd = cmd[1:]

    options = {
        "-t": ui_eliminate_all_expenses_of_same_type,
        "-lv": ui_eliminate_all_expenses_lower_than,
    }

    assert specific_command in options.keys(), "Invalid specific command."
    options[specific_command](expenses, cmd)


def ui_eliminate_all_expenses_of_same_type(
    expenses: list[list], cmd: list[str]
) -> None:
    if len(cmd) != 1:
        raise Exception("Invalid command parameters.")

    type = cmd[0]

    manager_eliminate_all_expenses_of_same_type(expenses, type)


def ui_eliminate_all_expenses_lower_than(expenses: list[list], cmd: list[str]) -> None:
    if len(cmd) != 1:
        raise Exception("Invalid command parameters.")

    value = float(cmd[0])

    manager_eliminate_all_expenses_lower_than(expenses, value)
