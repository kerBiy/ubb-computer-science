class ModifyUI:
    def __init__(self, manager_student, manager_subject) -> None:
        self.manager_student = manager_student
        self.manager_subject = manager_subject

    def modify_student(self, cmd: list[str]) -> None:
        if len(cmd) != 2:
            raise Exception("Invalid command arguments.")

        student_id = int(cmd[0])
        new_name = cmd[1].strip()

        self.manager_student.modify(student_id, new_name)
        print(f"Student {student_id} name has been changed to '{new_name}'.")

    def modify_subject(self, cmd: list[str]) -> None:
        if len(cmd) != 3:
            raise Exception("Invalid command parameters.")

        subject_id = int(cmd[0])
        new_name = cmd[1].strip()
        new_professor = cmd[2].strip()

        self.manager_subject.modify(subject_id, new_name, new_professor)
        print(
            f"Subject {subject_id} name has been changed to '{new_name}' and the professor to '{new_professor}'."
        )
