class PrintUI:
    def __init__(self, manager_student, manager_subject) -> None:
        self.manager_student = manager_student
        self.manager_subject = manager_subject

    def print_students(self, cmd: list[str]) -> None:
        if not cmd == [""]:
            raise Exception("Invalid command parameters.")

        student_list = self.manager_student.print()
        print("\nSTUDENTS LIST:")
        print(student_list)

    def print_subjects(self, cmd: list[str]) -> None:
        if not cmd == [""]:
            raise Exception("Invalid command parameters.")

        subject_list = self.manager_subjects.print()
        print("\nSUBJECTS LIST:")
        print(subject_list)
