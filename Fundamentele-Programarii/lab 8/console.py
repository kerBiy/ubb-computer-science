from ui.printing import ui_print_subjects, ui_print_students
from ui.add import ui_add_student, ui_add_subject
from ui.delete import ui_delete_student, ui_delete_subject
from ui.modify import ui_modify_student, ui_modify_subject
from ui.search import (
    ui_search_student_by_id,
    ui_search_subject_by_id,
    ui_search_student_by_name,
    ui_search_subject_by_name,
    ui_search_subject_by_prof,
)


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
        "print_stud": ui_print_students,
        "print_sub": ui_print_subjects,
        "add_stud": ui_add_student,
        "add_sub": ui_add_subject,
        "del_stud": ui_delete_student,
        "del_sub": ui_delete_subject,
        "mod_stud": ui_modify_student,
        "mod_sub": ui_modify_subject,
        "search_stud_id": ui_search_student_by_id,
        "search_sub_id": ui_search_subject_by_id,
        "search_stud_name": ui_search_student_by_name,
        "search_sub_name": ui_search_subject_by_name,
        "search_prof": ui_search_subject_by_prof,
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
