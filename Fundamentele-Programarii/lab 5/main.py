from validate.tests import test_functions
from infrastructure.utils import get_command, help_menu
from ui.expenses import ui_print_expenses
from ui.adding import ui_add_expense, ui_modify_expense
from ui.deleting import ui_delete_command
from ui.searching import ui_search_command
from ui.printing import ui_print_command
from ui.filtering import ui_filter_command


def console_application() -> None:
    expenses = []

    options = {
        "list": ui_print_expenses,
        "add": ui_add_expense,
        "modify": ui_modify_expense,
        "delete": ui_delete_command,
        "search": ui_search_command,
        "print": ui_print_command,
        "filter": ui_filter_command,
    }

    while True:
        cmd = get_command("\n>>> ")
        first_command = cmd[0].strip() if cmd else ""
        cmd = cmd[1:]

        if first_command == "exit":
            print("Exiting the program...")
            return
        if first_command == "help":
            print(help_menu())

        try:
            assert first_command in options.keys(), "Invalid input."
            options[first_command](expenses, cmd)
        except ValueError as ve:
            print(ve)
        except Exception as ex:
            print(ex)


if __name__ == "__main__":
    test_functions()
    console_application()
