from business.manager import manager_add_expense, manager_modify_expense


def ui_add_expense(expenses: list[list], cmd: list[str]) -> None:
    if len(cmd) != 4:
        raise Exception("Invalid command parameters.")

    apartment = int(cmd[0])
    value = float(cmd[1])
    type = cmd[2]
    date = cmd[3]

    manager_add_expense(expenses, apartment, value, type, date)
    print("Expense added in the list.")


def ui_modify_expense(expenses: list[list], cmd: list[str]) -> None:
    if len(cmd) != 5:
        raise Exception("Invalid command parameters.")

    id = int(cmd[0])
    apartment = int(cmd[1])
    value = float(cmd[2])
    type = cmd[3]
    date = cmd[4]

    manager_modify_expense(expenses, id, apartment, value, type, date)
    print("Expense modified.")
