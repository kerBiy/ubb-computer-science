from business.manager import manager_add_student, manager_add_subject


def ui_add(students: list[list], subjects: list[list], cmd: list[str]) -> None:
    if not cmd:
        raise Exception("Invalid command parameters.")

    specific_command = cmd.pop(0).strip()

    if specific_command == "-st":
        ui_add_student(students, cmd)
    elif specific_command == "-sb":
        ui_add_subject(subjects, cmd)
    else:
        raise Exception("Invalid specific command.")


def ui_add_student(students: list[list], cmd: list[str]) -> None:
    # if len(cmd) != 2:
    #     raise Exception("Invalid command parameters.")

    student_id = int(cmd[0])
    student_name = " ".join(cmd[1:])

    manager_add_student(students, student_id, student_name)
    print("Student added in the list.")


def ui_add_subject(subjects: list[list], cmd: list[str]) -> None:
    if len(cmd) != 3:
        raise Exception("Invalid command parameters.")

    subject_id = int(cmd[0])
    subject_name = cmd[1]
    professor = cmd[2]

    manager_add_subject(subjects, subject_id, subject_name, professor)
    print("Subject added in the list.")
