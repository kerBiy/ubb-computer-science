from business.manager import manager_search_all_expenses_of_type


def ui_search_command(expenses: list[list], cmd: list[str]) -> None:
    if not cmd:
        raise Exception("Invalid command parameters.")

    specific_command = cmd[0]
    cmd = cmd[1:]

    options = {"-t": ui_search_all_expenses_of_type}

    assert specific_command in options.keys(), "Invalid specific command."
    options[specific_command](expenses, cmd)


def ui_search_all_expenses_of_type(expenses: list[list], cmd: list[str]) -> None:
    if len(cmd) != 1:
        raise Exception("Invalid command parameters.")

    type = cmd[0]

    manager_search_all_expenses_of_type(expenses, type)
