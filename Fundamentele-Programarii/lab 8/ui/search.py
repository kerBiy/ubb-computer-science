class SearchUI:
    def __init__(self, manager_student, manager_subject) -> None:
        self.student_manager = manager_student
        self.subject_manager = manager_subject

    def search_student_id(self, cmd: list[str]) -> None:
        if len(cmd) != 1:
            raise Exception("Invalid command arguments.")

        student_id = int(cmd[0])

        student = self.student_manager.search_id(student_id)
        print(student)

    def search_subject_id(self, cmd: list[str]) -> None:
        if len(cmd) != 1:
            raise Exception("Invalid command parameters.")

        subject_id = int(cmd[0])

        subject = self.subject_manager.search_id(subject_id)
        print(subject)

    def search_student_name(self, cmd: list[str]) -> None:
        if len(cmd) != 1:
            raise Exception("Invalid command arguments.")

        student_name = cmd[0].strip()

        student_list = self.student_manager.search_name(student_name)

        print(f"\nThe students that have the name '{student_name}' are:")
        print(student_list)

    def search_subject_name(self, cmd: list[str]) -> None:
        if len(cmd) != 1:
            raise Exception("Invalid command arguments.")

        subject_name = cmd[0].strip()

        subject_list = self.subject_manager.search_name(subject_name)

        print(f"\nThe subjects that have the name '{subject_name}' are:")
        print(subject_list)

    def search_prof(self, cmd: list[str]) -> None:
        if len(cmd) != 1:
            raise Exception("Invalid command arguments.")

        professor = cmd[0].strip()

        subject_list = self.subject_manager.search_prof(professor)

        print(f"\nThe subjects that have the professor '{professor}' are:")
        print(subject_list)
