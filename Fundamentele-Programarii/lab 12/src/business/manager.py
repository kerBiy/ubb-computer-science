from domain.validator import ValidatorStudent, ValidatorSubject, ValidatorGrade
from infrastructure.fileRepository import (
    StudentFileRepository,
    SubjectFileRepository,
    GradeFileRepository,
)
from domain.entity import Student, Subject, Grade
from domain.dto import GradeDTO, StudentDTO


class ManagerStudent:
    def __init__(self, student_repository: StudentFileRepository) -> None:
        self.students = student_repository
        self.students.load_students()

    def get_all(self) -> list[Student]:
        return self.students.items

    def print(self) -> str:
        return self.students

    def add(self, student_id: int, name: str) -> None:
        if self.students.search(student_id):
            raise Exception(f"The student {student_id} already exists!")

        new_student = Student(student_id, name)
        ValidatorStudent.validate(new_student)
        self.students.add(new_student)
        self.students.save_students()

    def delete(self, student_id: int) -> None:
        if not self.students.search(student_id):
            raise Exception(f"The student {student_id} does not exist!")

        self.students.delete(student_id)
        self.students.save_students()

    def modify(self, student_id: int, new_name: str) -> None:
        if not self.students.search(student_id):
            raise Exception(f"The student {student_id} does not exist!")

        ValidatorStudent.validate_name(new_name)
        self.students.modify(student_id, new_name)
        self.students.save_students()

    def search(self, student_id: int) -> str:
        student = self.students.search(student_id)

        if not student:
            raise Exception(f"Student {student_id} does not exist!")

        return student


# /----- Subject -----/


class ManagerSubject:
    def __init__(self, subject_repository: SubjectFileRepository) -> None:
        self.subjects = subject_repository
        self.subjects.load_subjects()

    def get_all(self) -> list[Subject]:
        return self.subjects.items

    def print(self) -> str:
        return self.subjects

    def add(self, subject_id: int, name: str, professor: str) -> None:
        if self.subjects.search(subject_id):
            raise Exception(f"The subject {subject_id} already exists!")

        new_subject = Subject(subject_id, name, professor)
        ValidatorSubject.validate(new_subject)
        self.subjects.add(new_subject)
        self.subjects.save_subjects()

    def delete(self, subject_id: int) -> None:
        if not self.subjects.search(subject_id):
            raise Exception(f"The subject {subject_id} does not exist!")

        self.subjects.delete(subject_id)
        self.subjects.save_subjects()

    def modify(self, subject_id: int, new_name: str, new_professor: str) -> None:
        if not self.subjects.search(subject_id):
            raise Exception(f"The subject {subject_id} does not exist!")

        ValidatorSubject.validate_name(new_name)
        ValidatorSubject.validate_prof(new_professor)
        self.subjects.modify(subject_id, new_name, new_professor)
        self.subjects.save_subjects()

    def search(self, subject_id: int) -> tuple:
        subject = self.subjects.search(subject_id)

        if not subject:
            raise Exception(f"Subject {subject_id} does not exist!")

        return subject


# /----- Grade Book -----/


class ManagerGrade:
    def __init__(
        self,
        grade_book: GradeFileRepository,
        student_repository: StudentFileRepository,
        subject_repository: SubjectFileRepository,
    ) -> None:
        self.grades = grade_book
        self.students = student_repository
        self.subjects = subject_repository
        self.grades.load_grades()

    def print(self) -> str:
        return self.grades

    def assign(
        self, grade_id: int, student_id: int, subject_id: int, value: float
    ) -> None:
        if self.grades.search(grade_id):
            raise Exception(f"The grade {grade_id} already exists!")
        if not self.students.search(student_id):
            raise Exception(f"The student {student_id} does not exists!")
        if not self.subjects.search(subject_id):
            raise Exception(f"The subject {subject_id} does not exists!")

        new_grade = Grade(grade_id, student_id, subject_id, value)
        ValidatorGrade.validate(new_grade)
        self.grades.add(new_grade)
        self.grades.save_grades()

    def change(
        self, grade_id: int, new_student_id: int, new_subject_id: int, new_value: float
    ) -> None:
        if not self.grades.search(grade_id):
            raise Exception(f"The grade {grade_id} does not exist!")
        if not self.students.search(new_student_id):
            raise Exception(f"The student {new_student_id} does not exists!")
        if not self.subjects.search(new_subject_id):
            raise Exception(f"The subject {new_subject_id} does not exists!")

        ValidatorGrade.validate_value(new_value)
        self.grades.modify(grade_id, new_student_id, new_subject_id, new_value)
        self.grades.save_grades()

    def search(self, grade_id: int) -> str:
        grade = self.grades.search(grade_id)

        if not grade:
            raise Exception(f"Grade {grade_id} does not exist!")

        return grade

    def get_grades_dto_list(self) -> list[GradeDTO]:
        grade_list = self.grades.items
        output_list = []

        for grade in grade_list:
            grade_id = grade.id
            student = self.students.search(grade.student_id)
            subject = self.subjects.search(grade.subject_id)
            value = grade.value

            dto = GradeDTO(grade_id, student, subject, value)
            output_list.append(dto)

        return output_list

    def get_students_dto_list(self) -> list[GradeDTO]:
        student_list = self.students.items
        output_list = []

        for student in student_list:
            student_id = student.id
            student_name = student.name

            grade_list = self.grades.items
            student_grades = list(
                filter(lambda x: x.student_id == student_id, grade_list)
            )

            dto = StudentDTO(student_id, student_name, student_grades)
            output_list.append(dto)

        return output_list

    def stats_by_name(self, subject_id: int) -> list[GradeDTO]:
        if not self.subjects.search(subject_id):
            raise Exception(f"The subject {subject_id} does not exists!")

        dto_list = self.get_grades_dto_list()
        list_one_subject = filter(lambda x: x.subject.id == subject_id, dto_list)
        sorted_list = sorted(list_one_subject, key=lambda x: x.student.name)

        return sorted_list

    def stats_by_value(self, subject_id: int) -> list[GradeDTO]:
        if not self.subjects.search(subject_id):
            raise Exception(f"The subject {subject_id} does not exists!")

        dto_list = self.get_grades_dto_list()
        list_one_subject = filter(lambda x: x.subject.id == subject_id, dto_list)
        sorted_list = sorted(list_one_subject, key=lambda x: x.value, reverse=True)

        return sorted_list

    def top20(self) -> list[StudentDTO]:
        dto_list = self.get_students_dto_list()
        sorted_list = sorted(dto_list, key=lambda x: x.average, reverse=True)

        top_list = []
        for i in range(len(sorted_list) // 5):
            top_list.append(sorted_list[i])

        return top_list

    def failing(self) -> list[StudentDTO]:
        dto_list = self.get_students_dto_list()

        failing_students = filter(lambda x: x.lowest_grade < 5, dto_list)
        sorted_list = sorted(failing_students, key=lambda x: (-x.lowest_grade, x.name))

        return sorted_list
