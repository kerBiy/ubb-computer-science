from business.manager import manager_modify_student, manager_modify_subject


def ui_modify_student(students: list, subjects: list[list], cmd: list[str]) -> None:
    if len(cmd) != 2:
        raise Exception("Invalid command arguments.")

    student_id = int(cmd[0])
    new_student_name = cmd[1].strip()

    manager_modify_student(students, student_id, new_student_name)
    print(f"Student {student_id} name has been changed to '{new_student_name}'.")


def ui_modify_subject(students: list, subjects: list[list], cmd: list[str]) -> None:
    if len(cmd) != 3:
        raise Exception("Invalid command parameters.")

    subject_id = int(cmd[0])
    new_subject_name = cmd[1].strip()
    new_professor = cmd[2].strip()

    manager_modify_subject(subjects, subject_id, new_subject_name, new_professor)
    print(
        f"Subject {subject_id} name has been changed to '{new_subject_name}' and the professor to '{new_professor}'."
    )
