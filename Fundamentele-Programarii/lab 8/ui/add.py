class AddUI:
    def __init__(self, manager_student, manager_subject) -> None:
        self.manager_student = manager_student
        self.manager_subject = manager_subject

    def add_student(self, cmd: list[str]) -> None:
        if len(cmd) != 2:
            raise Exception("Invalid command arguments.")

        student_id = int(cmd[0])
        student_name = cmd[1].strip()

        self.manager_student.add(student_id, student_name)
        print("Student added in the list.")

    def add_subject(self, cmd: list[str]) -> None:
        if len(cmd) != 3:
            raise Exception("Invalid command parameters.")

        subject_id = int(cmd[0])
        subject_name = cmd[1].strip()
        professor = cmd[2].strip()

        self.manager_subject.add(subject_id, subject_name, professor)
        print("Subject added in the list.")
