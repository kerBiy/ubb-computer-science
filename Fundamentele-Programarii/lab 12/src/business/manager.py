from domain.validator import ValidatorStudent, ValidatorSubject, ValidatorGrade
from infrastructure.fileRepository import (
    StudentFileRepository,
    SubjectFileRepository,
    GradeFileRepository,
)
from domain.entity import Student, Subject, Grade
from domain.dto import GradeDTO, StudentDTO
from sorting.sorting import Sorting
from sorting.algorithms.algorithm import Algorithm
from domain.recursive import Recursive


class ManagerStudent:
    def __init__(self, student_repository: StudentFileRepository) -> None:
        self.students = student_repository
        self.students.load_students()

    def print(self) -> str:
        return self.students

    def add(self, student_id: int, name: str) -> None:
        if self.students.find(student_id):
            raise Exception(f"The student {student_id} already exists!")

        new_student = Student(student_id, name)
        ValidatorStudent.validate(new_student)

        self.students.add(new_student)
        self.students.save_students()

    def delete(self, student_id: int) -> None:
        if not self.students.find(student_id):
            raise Exception(f"The student {student_id} does not exist!")

        self.students.delete(student_id)
        self.students.save_students()

    def modify(self, student_id: int, new_name: str) -> None:
        if not self.students.find(student_id):
            raise Exception(f"The student {student_id} does not exist!")

        new_student = Student(student_id, new_name)
        ValidatorStudent.validate(new_student)

        self.students.modify(student_id, new_student)
        self.students.save_students()

    def find(self, student_id: int) -> str:
        student = self.students.find(student_id)

        if not student:
            raise Exception(f"Student {student_id} does not exist!")

        return student


# /----- Subject -----/


class ManagerSubject:
    def __init__(self, subject_repository: SubjectFileRepository) -> None:
        self.subjects = subject_repository
        self.subjects.load_subjects()

    def print(self) -> str:
        return self.subjects

    def add(self, subject_id: int, name: str, professor: str) -> None:
        if self.subjects.find(subject_id):
            raise Exception(f"The subject {subject_id} already exists!")

        new_subject = Subject(subject_id, name, professor)
        ValidatorSubject.validate(new_subject)
        self.subjects.add(new_subject)
        self.subjects.save_subjects()

    def delete(self, subject_id: int) -> None:
        if not self.subjects.find(subject_id):
            raise Exception(f"The subject {subject_id} does not exist!")

        self.subjects.delete(subject_id)
        self.subjects.save_subjects()

    def modify(self, subject_id: int, new_name: str, new_professor: str) -> None:
        if not self.subjects.find(subject_id):
            raise Exception(f"The subject {subject_id} does not exist!")

        new_subject = Subject(subject_id, new_name, new_professor)
        ValidatorSubject.validate(new_subject)

        self.subjects.modify(subject_id, new_subject)
        self.subjects.save_subjects()

    def find(self, subject_id: int) -> tuple:
        subject = self.subjects.find(subject_id)

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
        if self.grades.find(grade_id):
            raise Exception(f"The grade {grade_id} already exists!")
        if not self.students.find(student_id):
            raise Exception(f"The student {student_id} does not exists!")
        if not self.subjects.find(subject_id):
            raise Exception(f"The subject {subject_id} does not exists!")

        new_grade = Grade(grade_id, student_id, subject_id, value)
        ValidatorGrade.validate(new_grade)

        self.grades.add(new_grade)
        self.grades.save_grades()

    def change(
        self, grade_id: int, new_student_id: int, new_subject_id: int, new_value: float
    ) -> None:
        if not self.grades.find(grade_id):
            raise Exception(f"The grade {grade_id} does not exist!")
        if not self.students.find(new_student_id):
            raise Exception(f"The student {new_student_id} does not exists!")
        if not self.subjects.find(new_subject_id):
            raise Exception(f"The subject {new_subject_id} does not exists!")

        new_grade = Grade(grade_id, new_student_id, new_subject_id, new_value)
        ValidatorGrade.validate(new_grade)

        self.grades.modify(grade_id, new_grade)
        self.grades.save_grades()

    def find(self, grade_id: int) -> str:
        grade = self.grades.find(grade_id)

        if not grade:
            raise Exception(f"Grade {grade_id} does not exist!")

        return grade

    def get_grades_dto_list(self) -> list[GradeDTO]:
        grade_list = self.grades.items
        output_list = []

        for grade in grade_list:
            grade_id = grade.id
            student = self.students.find(grade.student_id)
            subject = self.subjects.find(grade.subject_id)
            value = grade.value

            dto = GradeDTO(grade_id, student, subject, value)
            output_list.append(dto)

        return output_list

    def get_students_dto_list(self) -> list[StudentDTO]:
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
        if not self.subjects.find(subject_id):
            raise Exception(f"The subject {subject_id} does not exists!")

        dto_list = self.get_grades_dto_list()
        list_one_subject = list(filter(lambda x: x.subject.id == subject_id, dto_list))

        Sorting.sort(
            list_one_subject,
            key=lambda x: x.student.name,
            algorithm=Algorithm.SELECTION_SORT,
        )

        return list_one_subject

    def stats_by_value(self, subject_id: int) -> list[GradeDTO]:
        if not self.subjects.find(subject_id):
            raise Exception(f"The subject {subject_id} does not exists!")

        dto_list = self.get_grades_dto_list()
        list_one_subject = list(filter(lambda x: x.subject.id == subject_id, dto_list))

        Sorting.sort(
            list_one_subject,
            key=lambda x: x.value,
            reverse=True,
            algorithm=Algorithm.SHAKE_SORT,
        )

        return list_one_subject

    def top20(self) -> list[StudentDTO]:
        dto_list = self.get_students_dto_list()

        Sorting.sort(
            dto_list,
            key=lambda x: x.average,
            algorithm=Algorithm.SELECTION_SORT,
        )

        Recursive.get_20_percent(dto_list, len(dto_list))
        return dto_list

    def failing(self) -> list[StudentDTO]:
        dto_list = self.get_students_dto_list()
        failing_students = list(filter(lambda x: x.lowest_grade < 5, dto_list))

        Sorting.sort(
            failing_students,
            key=lambda x: (-x.lowest_grade, x.name),
            algorithm=Algorithm.SHAKE_SORT,
        )

        return failing_students
