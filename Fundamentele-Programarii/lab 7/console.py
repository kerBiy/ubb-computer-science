from ui.print import ui_print
from ui.add import ui_add_student, ui_add_subject


def get_first_command(command: str) -> str:
    command = command.split()
    first_command = command[0].strip() if command else ""
    cmd_arguments = " ".join(command[1:])
    cmd_arguments = cmd_arguments.split(",")

    return first_command, cmd_arguments


def run_console_application() -> None:
    students = []
    subjects = []

    options = {
        "print": ui_print,
        "add_stud": ui_add_student,
        "add_sub": ui_add_subject,
    }

    while True:
        command = input("\n>>> ")
        first_command, cmd_arguments = get_first_command(command)

        if first_command == "exit":
            print("Exiting the program...")
            return

        try:
            assert first_command in options.keys(), "Invalid first command."
            options[first_command](students, subjects, cmd_arguments)
        except ValueError as ve:
            print(ve)
        except Exception as e:
            print(e)
