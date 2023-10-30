from business.manager import (
    manager_delete_all_expenses_from_apartment,
    manager_delete_all_consecutive_expenses,
    manager_delete_all_expenses_of_same_type,
)


def ui_delete_command(expenses: list[dict], cmd: list[str]) -> None:
    if not cmd:
        raise Exception("Invalid command parameters.")

    specific_command = cmd[0]
    cmd = cmd[1:]

    options = {
        "-a": ui_delete_all_expenses_from_apartment,
        "-c": ui_delete_all_consecutive_expenses,
        "-t": ui_delete_all_expenses_of_same_type,
    }

    assert specific_command in options.keys(), "Invalid specific command."
    options[specific_command](expenses, cmd)


def ui_delete_all_expenses_from_apartment(expenses: list[dict], cmd: list[str]) -> None:
    if len(cmd) != 1:
        raise Exception("Invalid command parameters.")

    apartment = int(cmd[0])

    manager_delete_all_expenses_from_apartment(expenses, apartment)
    print(f"Deleting all expenses from {apartment} apartment.")


def ui_delete_all_consecutive_expenses(expenses: list[dict], cmd: list[str]) -> None:
    if len(cmd) != 2:
        raise Exception("Invalid command parameters.")

    first_apartment = int(cmd[0])
    second_apartment = int(cmd[1])

    manager_delete_all_consecutive_expenses(expenses, first_apartment, second_apartment)
    print(
        f"Deleting all expenses from {first_apartment} apartment to {second_apartment} apartment."
    )


def ui_delete_all_expenses_of_same_type(expenses: list[dict], cmd: list[str]) -> None:
    if len(cmd) != 1:
        raise Exception("Invalid command parameters.")

    type = cmd[0]

    manager_delete_all_expenses_of_same_type(expenses, type)
    print(f"Deleting all expenses of type {type}.")
