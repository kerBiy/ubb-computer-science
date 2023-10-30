from business.manager import manager_print_total_sum_expenses_of_type


def ui_print_command(expenses: list[dict], cmd: list[str]) -> None:
    if not cmd:
        raise Exception("Invalid command parameters.")

    specific_command = cmd[0]
    cmd = cmd[1:]

    options = {"-ts": ui_print_total_sum_expenses_of_type}

    assert specific_command in options.keys(), "Invalid specific command."
    options[specific_command](expenses, cmd)


def ui_print_total_sum_expenses_of_type(expenses: list[dict], cmd: list[str]) -> None:
    if len(cmd) != 1:
        raise Exception("Invalid command parameters.")

    type = cmd[0]

    manager_print_total_sum_expenses_of_type(expenses, type)
