class PrintUI:
    def __init__(self, manager_student, manager_subject) -> None:
        self.manager_students = manager_student
        self.manager_subjects = manager_subject

    def print_students(self, cmd: list[str]) -> None:
        if not cmd == [""]:
            raise Exception("Invalid command parameters.")

        student_list = self.manager_students.print()

        if student_list:
            print("\nSTUDENTS LIST:")
            print(student_list)
        else:
            print("The student list is empty.")

    def print_subjects(self, cmd: list[str]) -> None:
        if not cmd == [""]:
            raise Exception("Invalid command parameters.")

        subject_list = self.manager_subjects.print()

        if len(subject_list):
            print("\nSUBJECTS LIST:")
            print(subject_list)
        else:
            print("The subjects list is empty.")
