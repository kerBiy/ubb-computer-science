from business.manager import manager_add_student, manager_add_subject


def ui_add_student(students: list, subjects: list[list], cmd: list[str]) -> None:
    if len(cmd) != 2:
        raise Exception("Invalid command arguments.")

    student_id = int(cmd[0])
    student_name = cmd[1].strip()

    manager_add_student(students, student_id, student_name)
    print("Student added in the list.")


def ui_add_subject(students: list, subjects: list[list], cmd: list[str]) -> None:
    if len(cmd) != 3:
        raise Exception("Invalid command parameters.")

    subject_id = int(cmd[0])
    subject_name = cmd[1].strip()
    professor = cmd[2].strip()

    manager_add_subject(subjects, subject_id, subject_name, professor)
    print("Subject added in the list.")
