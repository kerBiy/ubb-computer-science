from business import manager_search_all_expenses_of_type


def ui_search_command(expenses: list[dict], cmd: list[str]) -> None:
    if not cmd:
        raise Exception("Invalid command parameters.")

    specific_command = cmd[0]
    cmd = cmd[1:]

    options = {"-t": ui_search_all_expenses_of_type}

    options[specific_command](expenses, cmd)


def ui_search_all_expenses_of_type(expenses: list[dict], cmd: list[str]) -> None:
    if len(cmd) != 1:
        raise Exception("Invalid command parameters.")

    type = cmd[0]

    manager_search_all_expenses_of_type(expenses, type)
