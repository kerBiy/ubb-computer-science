from business import *


def ui_print_expenses(expenses: list[dict], cmd: list[str]) -> None:
    if len(cmd):
        raise Exception("Invalid command parameters.")

    manager_print_expenses(expenses)


# /----- Adding -----/


def ui_add_expense(expenses: list[dict], cmd: list[str]) -> None:
    if len(cmd) != 4:
        raise Exception("Invalid command parameters.")

    apartment = int(cmd[0])
    value = float(cmd[1])
    type = cmd[2]
    date = cmd[3]

    manager_add_expense(expenses, apartment, value, type, date)
    print("Expense added in the list.")


def ui_modify_expense(expenses: list[dict], cmd: list[str]) -> None:
    if len(cmd) != 5:
        raise Exception("Invalid command parameters.")

    id = int(cmd[0])
    apartment = int(cmd[1])
    value = float(cmd[2])
    type = cmd[3]
    date = cmd[4]

    manager_modify_expense(expenses, id, apartment, value, type, date)
    print("Expense modified.")


# /----- Deleting -----/


def ui_delete_command(expenses: list[dict], cmd: list[str]) -> None:
    if not cmd:
        raise Exception("Invalid command parameters.")

    specific_command = cmd[0]
    cmd = cmd[1:]

    options = {
        "-ap": ui_delete_all_expenses_from_apartment,
        "-c": ui_delete_all_consecutive_expenses,
        "-ty": ui_delete_all_expenses_of_same_type,
    }

    options[specific_command](expenses, cmd)


def ui_delete_all_expenses_from_apartment(expenses: list[dict], cmd: list[str]) -> None:
    if len(cmd) != 1:
        raise Exception("Invalid command parameters.")

    apartment = int(cmd[0])

    manager_delete_all_expenses_from_apartment(expenses, apartment)


def ui_delete_all_consecutive_expenses(expenses: list[dict], cmd: list[str]) -> None:
    if len(cmd) != 2:
        raise Exception("Invalid command parameters.")

    first_apartment = int(cmd[0])
    second_apartment = int(cmd[1])

    manager_delete_all_consecutive_expenses(expenses, first_apartment, second_apartment)


def ui_delete_all_expenses_of_same_type(expenses: list[dict], cmd: list[str]) -> None:
    if len(cmd) != 1:
        raise Exception("Invalid command parameters.")

    type = cmd[0]

    manager_delete_all_expenses_of_same_type(expenses, type)
