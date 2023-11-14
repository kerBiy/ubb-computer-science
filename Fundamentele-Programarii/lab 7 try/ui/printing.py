from business.manager import manager_print_subjects


def ui_print_students(students, subjects: list[list], cmd: list[str]) -> None:
    if not cmd == [""]:
        raise Exception("Invalid command parameters.")
    if students.get_len() == 0:
        raise Exception("Student list is empty.")

    print("\nSTUDENTS LIST:")
    print(students.print_students())


def ui_print_subjects(students, subjects: list[list], cmd: list[str]) -> None:
    if not cmd == [""]:
        raise Exception("Invalid command parameters.")
    if not subjects:
        raise Exception("Subject list is empty.")

    subject_list = manager_print_subjects(subjects)
    print("\nSUBJECTS LIST:")
    print(subject_list)
