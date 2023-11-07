from ui.print import ui_print
from ui.add import ui_add


def run_console_application() -> None:
    students = []
    subjects = []

    options = {"print": ui_print, "add": ui_add}

    while True:
        command = input("\n>>> ").split()
        first_command = command[0].strip() if command else ""
        cmd_arguments = command[1:]

        if first_command == "exit":
            print("Exiting the program...")
            return

        try:
            assert first_command in options.keys(), "Invalid input."
            options[first_command](students, subjects, cmd_arguments)
        except ValueError as ve:
            print(ve)
        except Exception as e:
            print(e)
