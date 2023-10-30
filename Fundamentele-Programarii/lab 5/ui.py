from business import manager_add_expense


def ui_add_expense(expenses: list[dict], cmd: list[str]) -> None:
    if len(cmd) != 4:
        raise Exception("Invalid command parameters.")

    apartment = int(cmd[0])
    value = float(cmd[1])
    type = cmd[2]
    date = cmd[3]

    manager_add_expense(expenses, apartment, value, type, date)
