from tests import test_functions
from utils import get_command
from ui import ui_add_expense


def console_application() -> None:
    expenses = []

    while True:
        cmd = get_command("\n>>> ")
        first_command = cmd[0].strip()
        cmd = cmd[1:]

        if first_command == "exit":
            print("Exiting the program...")
            return
        elif first_command == "add":
            try:
                ui_add_expense(expenses, cmd)
            except ValueError as ve:
                print(ve)
            except Exception as ex:
                print(ex)
        else:
            print("Invalid command.")


if __name__ == "__main__":
    test_functions()
    console_application()
