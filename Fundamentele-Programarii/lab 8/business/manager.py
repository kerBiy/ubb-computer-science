from validate.validator import ValidatorStudent, ValidatorSubject
from infrastructure.domain import Student, Subject
from infrastructure.repository import RepoStudent, RepoSubject


class ManagerStudent:
    def __init__(self) -> None:
        self.students = RepoStudent()
        self.validator = ValidatorStudent()

    def print(self) -> str:
        return self.students

    def add(self, student_id: int, name: str) -> None:
        if self.students.search_id(student_id):
            raise Exception(f"The student {student_id} already exists!")

        new_student = Student(student_id, name)
        self.validator.validate(new_student)
        self.students.add(new_student)

    def delete(self, student_id: int) -> None:
        if not self.students.search_id(student_id):
            raise Exception(f"The student {student_id} does not exist!")

        self.validator.validate_id(student_id)
        self.students.delete(student_id)

    def modify(self, student_id: int, new_name: str) -> None:
        if not self.students.search_id(student_id):
            raise Exception(f"The student {student_id} does not exist!")

        self.validator.validate_name(new_name)
        self.students.modify(student_id, new_name)

    def search_id(self, student_id: int) -> str:
        student = self.students.search_id(student_id)

        if not student:
            raise Exception(f"Student {student_id} does not exist!")

        return student.name

    def search_name(self, student_name: str) -> None:
        student_list = self.students.search_name(student_name)

        if not student_list:
            raise Exception(f"Student '{student_name}' does not exist!")

        return student_list


# /----- Subject -----/


class ManagerSubject:
    def __init__(self) -> None:
        self.subjects = RepoSubject()
        self.validator = ValidatorSubject()

    def print(self) -> str:
        return self.subjects

    def add(self, subject_id: int, name: str, professor: str) -> None:
        if self.subjects.search_id(subject_id):
            raise Exception(f"The subject {subject_id} already exists!")

        new_subject = Subject(subject_id, name, professor)
        self.validator.validate(new_subject)
        self.subjects.add(new_subject)

    def delete(self, subject_id: int) -> None:
        if not self.subjects.search_id(subject_id):
            raise Exception(f"The subject {subject_id} does not exist!")

        self.validator.validate_id(subject_id)
        self.subjects.delete(subject_id)

    def modify(self, subject_id: int, new_name: str, new_professor: str) -> None:
        if not self.subjects.search_id(subject_id):
            raise Exception(f"The subject {subject_id} does not exist!")

        self.validator.validate_name(new_name)
        self.validator.validate_prof(new_professor)
        self.subjects.modify(subject_id, new_name, new_professor)

    def search_id(self, subject_id: int) -> tuple:
        subject = self.subjects.search_id(subject_id)

        if not subject:
            raise Exception(f"Subject {subject_id} does not exist!")

        return subject.name, subject.prof

    def search_name(self, subject_name: str) -> None:
        subject_list = self.subjects.search_name(subject_name)

        if not subject_list:
            raise Exception(f"Subject '{subject_name}' does not exist!")

        return subject_list

    def search_prof(self, professor: str) -> None:
        subject_list = self.subjects.search_prof(professor)

        if not subject_list:
            raise Exception(f"Professor '{professor}' does not exist!")

        return subject_list
