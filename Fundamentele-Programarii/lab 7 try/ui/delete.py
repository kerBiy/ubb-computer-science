from business.manager import manager_delete_student, manager_delete_subject


def ui_delete_student(students, subjects: list[list], cmd: list[str]) -> None:
    if len(cmd) != 1:
        raise Exception("Invalid command arguments.")

    student_id = int(cmd[0])

    manager_delete_student(students, student_id)
    print(f"Student {student_id} has been removed")


def ui_delete_subject(students, subjects: list[list], cmd: list[str]) -> None:
    if len(cmd) != 1:
        raise Exception("Invalid command parameters.")

    subject_id = int(cmd[0])

    manager_delete_subject(subjects, subject_id)
    print(f"Subject {subject_id} has been removed.")
