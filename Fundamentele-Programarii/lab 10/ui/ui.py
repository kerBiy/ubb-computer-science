class Ui:
    def __init__(self, student_manager, subject_manager, grade_manager) -> None:
        self.student_manager = student_manager
        self.subject_manager = subject_manager
        self.grade_manager = grade_manager
        self.work_with_files = False

    def load(self, cmd: list[str]) -> None:
        if not cmd == [""]:
            raise Exception("Invalid command parameters.")

        self.student_manager.load()
        self.subject_manager.load()
        self.grade_manager.load()

        self.work_with_files = True

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

    def print_grades(self, cmd: list[str]) -> None:
        if not cmd == [""]:
            raise Exception("Invalid command parameters.")

        grade_list = self.grade_manager.print()

        if len(grade_list):
            print("\nGRADES LIST:")
            print(grade_list)
        else:
            print("The grades list is empty.")

    # /----- Add -----/

    def add_student(self, cmd: list[str]) -> None:
        if len(cmd) != 2:
            raise Exception("Invalid command arguments.")

        student_id = int(cmd[0])
        student_name = cmd[1].strip()

        self.student_manager.add(student_id, student_name)
        if self.work_with_files:
            self.student_manager.save()
        print("Student added in the list.")

    def add_subject(self, cmd: list[str]) -> None:
        if len(cmd) != 3:
            raise Exception("Invalid command parameters.")

        subject_id = int(cmd[0])
        subject_name = cmd[1].strip()
        professor = cmd[2].strip()

        self.subject_manager.add(subject_id, subject_name, professor)
        if self.work_with_files:
            self.subject_manager.save()
        print("Subject added in the list.")

    def add_grade(self, cmd: list[str]) -> None:
        if len(cmd) != 4:
            raise Exception("Invalid command parameters.")

        grade_id = int(cmd[0])
        student_id = int(cmd[1])
        subject_id = int(cmd[2])
        value = float(cmd[3])

        self.grade_manager.add(grade_id, student_id, subject_id, value)
        if self.work_with_files:
            self.grade_manager.save()

        print("Grade added in the list.")

    # /----- Delete -----/

    def delete_student(self, cmd: list[str]) -> None:
        if cmd == [""] or len(cmd) > 1:
            raise Exception("Invalid command arguments.")

        student_id = int(cmd[0])

        self.student_manager.delete(student_id)
        if self.work_with_files:
            self.student_manager.save()
        print(f"Student {student_id} has been removed")

    def delete_subject(self, cmd: list[str]) -> None:
        if cmd == [""] or len(cmd) > 1:
            raise Exception("Invalid command parameters.")

        subject_id = int(cmd[0])

        self.subject_manager.delete(subject_id)
        if self.work_with_files:
            self.subject_manager.save()

        print(f"Subject {subject_id} has been removed.")

    def delete_grade(self, cmd: list[str]) -> None:
        if cmd == [""] or len(cmd) > 1:
            raise Exception("Invalid command parameters.")

        grade_id = int(cmd[0])

        self.grade_manager.delete(grade_id)
        if self.work_with_files:
            self.grade_manager.save()

        print(f"Grade {grade_id} has been removed.")

    # /----- Modify -----/

    def modify_student(self, cmd: list[str]) -> None:
        if len(cmd) != 2:
            raise Exception("Invalid command arguments.")

        student_id = int(cmd[0])
        new_name = cmd[1].strip()

        self.student_manager.modify(student_id, new_name)
        if self.work_with_files:
            self.student_manager.save()

        print(f"Student {student_id} name has been changed to '{new_name}'.")

    def modify_subject(self, cmd: list[str]) -> None:
        if len(cmd) != 3:
            raise Exception("Invalid command parameters.")

        subject_id = int(cmd[0])
        new_name = cmd[1].strip()
        new_professor = cmd[2].strip()

        self.subject_manager.modify(subject_id, new_name, new_professor)
        if self.work_with_files:
            self.subject_manager.save()

        print(
            f"Subject {subject_id} name has been changed to '{new_name}' and the professor to '{new_professor}'."
        )

    def modify_grade(self, cmd: list[str]) -> None:
        if len(cmd) != 4:
            raise Exception("Invalid command parameters.")

        grade_id = int(cmd[0])
        new_student_id = int(cmd[1])
        new_subject_id = int(cmd[2])
        new_value = float(cmd[3])

        self.grade_manager.modify(grade_id, new_student_id, new_subject_id, new_value)
        if self.work_with_files:
            self.grade_manager.save()

        print(
            f"Grade {grade_id} student has been changed to '{new_subject_id}', the subject to '{new_subject_id}' and the value to {new_value}."
        )

    # /----- Search -----/

    def search_student_id(self, cmd: list[str]) -> None:
        if cmd == [""] or len(cmd) > 1:
            raise Exception("Invalid command arguments.")

        student_id = int(cmd[0])

        student = self.student_manager.search_id(student_id)
        print(student)

    def search_subject_id(self, cmd: list[str]) -> None:
        if cmd == [""] or len(cmd) > 1:
            raise Exception("Invalid command parameters.")

        subject_id = int(cmd[0])

        subject = self.subject_manager.search_id(subject_id)
        print(subject)

    def search_grade_id(self, cmd: list[str]) -> None:
        if cmd == [""] or len(cmd) > 1:
            raise Exception("Invalid command parameters.")

        grade_id = int(cmd[0])

        grade = self.grade_manager.search_id(grade_id)
        print(grade)

    # /----- Stats -----/

    def stats(self, cmd: list[str]) -> None:
        if cmd == [""] or len(cmd) > 1:
            raise Exception("Invalid command arguments.")

        subject_id = int(cmd[0])

        output = self.grade_manager.stats(subject_id)
        print(output)

    def stats_ordered(self, cmd: list[str]) -> None:
        if cmd == [""] or len(cmd) > 1:
            raise Exception("Invalid command arguments.")

        subject_id = int(cmd[0])

        output = self.grade_manager.stats_ordered(subject_id)
        print(output)

    def top20(self, cmd: list[str]) -> None:
        if not cmd == [""]:
            raise Exception("Invalid command parameters.")

        output = self.grade_manager.top20()
        print(output)

    def failing(self, cmd: list[str]) -> None:
        if not cmd == [""]:
            raise Exception("Invalid command parameters.")

        output = self.grade_manager.failing()
        print(output)
