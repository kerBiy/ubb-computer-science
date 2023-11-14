class DeleteUI:
    def __init__(self, manager_student, manager_subject) -> None:
        self.manager_student = manager_student
        self.manager_subject = manager_subject

    def delete_student(self, cmd: list[str]) -> None:
        if len(cmd) != 1:
            raise Exception("Invalid command arguments.")

        student_id = int(cmd[0])

        self.manager_student.delete(student_id)
        print(f"Student {student_id} has been removed")

    def delete_subject(self, cmd: list[str]) -> None:
        if len(cmd) != 1:
            raise Exception("Invalid command parameters.")

        subject_id = int(cmd[0])

        self.manager_subject.delete(subject_id)
        print(f"Subject {subject_id} has been removed.")
