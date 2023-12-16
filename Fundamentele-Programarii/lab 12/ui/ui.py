class Ui:
    def __init__(self, student_manager, subject_manager, grade_manager) -> None:
        self.student_manager = student_manager
        self.subject_manager = subject_manager
        self.grade_manager = grade_manager

    # /----- Print -----/

    def print_students(self, cmd: list[str]) -> None:
        if not cmd == [""]:
            raise Exception("Invalid command parameters.")

        student_list = self.student_manager.print()

        if student_list:
            print("\nSTUDENTS LIST:")
            print(student_list)
        else:
            print("The student list is empty.")

    def print_subjects(self, cmd: list[str]) -> None:
        if not cmd == [""]:
            raise Exception("Invalid command parameters.")

        subject_list = self.subject_manager.print()

        if len(subject_list):
            print("\nSUBJECTS LIST:")
            print(subject_list)
        else:
            print("The subjects list is empty.")

    # /----- Add -----/

    def add_student(self, cmd: list[str]) -> None:
        if len(cmd) != 2:
            raise Exception("Invalid command arguments.")

        student_id = int(cmd[0])
        student_name = cmd[1].strip()

        self.student_manager.add(student_id, student_name)
        print("Student added in the list.")

    def add_subject(self, cmd: list[str]) -> None:
        if len(cmd) != 3:
            raise Exception("Invalid command parameters.")

        subject_id = int(cmd[0])
        subject_name = cmd[1].strip()
        professor = cmd[2].strip()

        self.subject_manager.add(subject_id, subject_name, professor)
        print("Subject added in the list.")

    # /----- Delete -----/

    def delete_student(self, cmd: list[str]) -> None:
        if cmd == [""] or len(cmd) > 1:
            raise Exception("Invalid command arguments.")

        student_id = int(cmd[0])

        self.student_manager.delete(student_id)
        print(f"Student {student_id} has been removed")

    def delete_subject(self, cmd: list[str]) -> None:
        if cmd == [""] or len(cmd) > 1:
            raise Exception("Invalid command parameters.")

        subject_id = int(cmd[0])

        self.subject_manager.delete(subject_id)
        print(f"Subject {subject_id} has been removed.")

    # /----- Modify -----/

    def modify_student(self, cmd: list[str]) -> None:
        if len(cmd) != 2:
            raise Exception("Invalid command arguments.")

        student_id = int(cmd[0])
        new_name = cmd[1].strip()

        self.student_manager.modify(student_id, new_name)
        print(f"Student {student_id} name has been changed to '{new_name}'.")

    def modify_subject(self, cmd: list[str]) -> None:
        if len(cmd) != 3:
            raise Exception("Invalid command parameters.")

        subject_id = int(cmd[0])
        new_name = cmd[1].strip()
        new_professor = cmd[2].strip()

        self.subject_manager.modify(subject_id, new_name, new_professor)
        print(
            f"Subject {subject_id} name has been changed to '{new_name}' and the professor to '{new_professor}'."
        )

    # /----- Search -----/

    def search_student(self, cmd: list[str]) -> None:
        if cmd == [""] or len(cmd) > 1:
            raise Exception("Invalid command arguments.")

        student_id = int(cmd[0])

        student = self.student_manager.search(student_id)
        print(student)

    def search_subject(self, cmd: list[str]) -> None:
        if cmd == [""] or len(cmd) > 1:
            raise Exception("Invalid command parameters.")

        subject_id = int(cmd[0])

        subject = self.subject_manager.search(subject_id)
        print(subject)

    # /----- Grades -----/

    def print_grades(self, cmd: list[str]) -> None:
        if not cmd == [""]:
            raise Exception("Invalid command parameters.")

        grade_list = self.grade_manager.print()

        if len(grade_list):
            print("\nGRADES LIST:")
            print(grade_list)
        else:
            print("The grades list is empty.")

    def assign_grade(self, cmd: list[str]) -> None:
        if len(cmd) != 4:
            raise Exception("Invalid command parameters.")

        grade_id = int(cmd[0])
        student_id = int(cmd[1])
        subject_id = int(cmd[2])
        value = float(cmd[3])

        self.grade_manager.assign(grade_id, student_id, subject_id, value)
        print("Grade added in the list.")

    def change_grade(self, cmd: list[str]) -> None:
        if len(cmd) != 4:
            raise Exception("Invalid command parameters.")

        grade_id = int(cmd[0])
        new_student_id = int(cmd[1])
        new_subject_id = int(cmd[2])
        new_value = float(cmd[3])

        self.grade_manager.change(grade_id, new_student_id, new_subject_id, new_value)
        print(
            f"Grade {grade_id} student has been changed to '{new_subject_id}', the subject to '{new_subject_id}' and the value to {new_value}."
        )

    # /----- Stats -----/

    def stats_by_name(self, cmd: list[str]) -> None:
        if cmd == [""] or len(cmd) > 1:
            raise Exception("Invalid command arguments.")

        subject_id = int(cmd[0])

        student_list = self.grade_manager.stats_by_name(subject_id)

        if not student_list:
            raise Exception("There are no elements that fit this description")

        print(f"\nThe grades in alphabetical order at Subject {subject_id} are:")
        for student in student_list:
            print(student)

    def stats_by_value(self, cmd: list[str]) -> None:
        if cmd == [""] or len(cmd) > 1:
            raise Exception("Invalid command arguments.")

        subject_id = int(cmd[0])

        student_list = self.grade_manager.stats_by_value(subject_id)

        if not student_list:
            raise Exception("There are no elements that fit this description")

        print(f"\nThe grades in decreasing order at Subject {subject_id} are:")
        for student in student_list:
            print(student)

    def top20(self, cmd: list[str]) -> None:
        if not cmd == [""]:
            raise Exception("Invalid command parameters.")

        student_list = self.grade_manager.top20()

        if not student_list:
            raise Exception("There are no elements that fit this description")

        print(f"\nThe top 20% of students are:")
        for student in student_list:
            print(student)

    def failing(self, cmd: list[str]) -> None:
        if not cmd == [""]:
            raise Exception("Invalid command parameters.")

        student_list = self.grade_manager.failing()

        if not student_list:
            raise Exception("There are no elements that fit this description")

        print(f"\nThe students that are failing are:")
        for student in student_list:
            print(student)
