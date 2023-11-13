from business.manager import manager_search_student_by_id, manager_search_subject_by_id


def ui_search_student_by_id(
    students: list[list], subjects: list[list], cmd: list[str]
) -> None:
    if len(cmd) != 1:
        raise Exception("Invalid command arguments.")

    student_id = int(cmd[0])

    student_name = manager_search_student_by_id(students, student_id)
    print(f"{student_id}. {student_name}")


def ui_search_subject_by_id(
    students: list[list], subjects: list[list], cmd: list[str]
) -> None:
    if len(cmd) != 1:
        raise Exception("Invalid command parameters.")

    subject_id = int(cmd[0])

    subject_name, professor = manager_search_subject_by_id(subjects, subject_id)
    print(f"{subject_id}. {subject_name} (professor: {professor})")
