from business.manager import manager_print_students, manager_print_subjects


def ui_print_students(
    students: list[list], subjects: list[list], cmd: list[str]
) -> None:
    if not cmd == [""]:
        raise Exception("Invalid command parameters.")
    if not students:
        raise Exception("Student list is empty.")

    student_list = manager_print_students(students)
    print("\nSTUDENTS LIST:")
    print(student_list)


def ui_print_subjects(
    students: list[list], subjects: list[list], cmd: list[str]
) -> None:
    if not cmd == [""]:
        raise Exception("Invalid command parameters.")
    if not subjects:
        raise Exception("Subject list is empty.")

    subject_list = manager_print_subjects(subjects)
    print("\nSUBJECTS LIST:")
    print(subject_list)
