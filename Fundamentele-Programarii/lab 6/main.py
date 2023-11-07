from os import system
from validate.tests import test_functions
from infrastructure.utils import (
    get_command,
    print_help_menu,
    update_history,
    print_expenses,
)
from ui.adding import ui_add_expense, ui_modify_expense
from ui.deleting import ui_delete_command
from ui.searching import ui_search_command
from ui.printing import ui_print_command
from ui.filtering import ui_filter_command
from ui.undoing import undo


def console_application() -> None:
    expenses = []
    history = [[]]
    commands = []

    options = {
        "add": ui_add_expense,
        "modify": ui_modify_expense,
        "delete": ui_delete_command,
        "search": ui_search_command,
        "print": ui_print_command,
        "filter": ui_filter_command,
    }

    while True:
        if not commands:
            commands = get_command("\n>>> ")

        cmd = commands.pop(0).split()
        first_command = cmd[0].strip() if cmd else ""
        cmd_parameters = cmd[1:]

        if not cmd_parameters:
            if first_command == "exit":
                print("Exiting the program...")
                return

            if first_command == "help":
                print_help_menu()
            elif first_command == "undo":
                undo(expenses, history)
            elif first_command == "list":
                print_expenses(expenses)
            elif first_command == "clear":
                system("clear")
            else:
                print("Invalid input.")

        else:
            try:
                assert first_command in options.keys(), "Invalid input."
                options[first_command](expenses, cmd_parameters)
                update_history(expenses, history)
            except ValueError as ve:
                print(ve)
            except Exception as ex:
                print(ex)

        print()


if __name__ == "__main__":
    test_functions()
    console_application()
