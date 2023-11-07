from infrastructure.domain import (
    get_student_id,
    get_student_name,
    get_subject_id,
    get_subject_name,
    get_subject_prof,
)


def ui_print(students: list[list], subjects: list[list], cmd: list[str]) -> None:
    if len(cmd) != 1:
        raise Exception("Invalid command parameters.")

    specific_command = cmd[0].strip()

    if specific_command == "-st":
        print_students(students)
    elif specific_command == "-sb":
        print_subjects(subjects)
    else:
        raise Exception("Invalid specific command.")


def print_students(students: list[list]) -> None:
    print("\nSTUDENTS LIST:")
    for student in students:
        print(f"{get_student_id(student)}. {get_student_name(student)}")


def print_subjects(subjects: list[list]) -> None:
    print("\nSUBJECTS LIST:")
    for subject in subjects:
        print(
            f"{get_subject_id(subject)}. {get_subject_name(subject)} (teacher: {get_subject_prof(subject)})"
        )
