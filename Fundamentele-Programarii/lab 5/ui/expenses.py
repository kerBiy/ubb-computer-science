from business.manager import manager_print_expenses


def ui_print_expenses(expenses: list[list], cmd: list[str]) -> None:
    if len(cmd):
        raise Exception("Invalid command parameters.")

    manager_print_expenses(expenses)
