from infrastructure.repository import Repository
from domain.entity import Student, Subject, Grade


class StudentFileRepository(Repository):
    def __init__(self, file_name: str, student_list: dict = None):
        super().__init__(student_list)
        self.__file_name = file_name

    def load_students(self) -> None:
        with open(self.__file_name, "r") as file:
            for line in file:
                record = line.strip().split(",")
                new_student = Student(int(record[0]), record[1])
                self.add(new_student)

    def save_students(self):
        with open(self.__file_name, "w") as file:
            for student in self.items:
                new_line = f"{student.id},{student.name}\n"
                file.write(new_line)


class SubjectFileRepository(Repository):
    def __init__(self, file_name: str, subject_list: dict = None):
        super().__init__(subject_list)
        self.__file_name = file_name

    def load_subjects(self):
        with open(self.__file_name, "r") as file:
            for line in file:
                record = line.strip().split(",")
                new_subject = Subject(int(record[0]), record[1], record[2])
                self.add(new_subject)

    def save_subjects(self):
        with open(self.__file_name, "w") as file:
            for subject in self.items:
                new_line = f"{subject.id},{subject.name},{subject.prof}\n"
                file.write(new_line)


class GradeFileRepository(Repository):
    def __init__(self, file_name: str, grade_list: dict = None):
        super().__init__(grade_list)
        self.__file_name = file_name

    def load_grades(self):
        with open(self.__file_name, "r") as file:
            for line in file:
                record = line.strip().split(",")
                new_grade = Grade(
                    int(record[0]), int(record[1]), int(record[2]), float(record[3])
                )
                self.add(new_grade)

    def save_grades(self):
        with open(self.__file_name, "w") as file:
            for grade in self.items:
                new_line = (
                    f"{grade.id},{grade.student_id},{grade.subject_id},{grade.value}\n"
                )
                file.write(new_line)
