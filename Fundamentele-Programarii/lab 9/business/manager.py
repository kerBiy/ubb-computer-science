from domain.validator import ValidatorStudent, ValidatorSubject, ValidatorGrade
from infrastructure.repository import RepoStudent, RepoSubject, GradeBook
from domain.domain import Student, Subject, Grade


class ManagerStudent:
    def __init__(self, student_repository: RepoStudent) -> None:
        self.students = student_repository

    def print(self) -> str:
        return self.students

    def add(self, student_id: int, name: str) -> None:
        if self.students.search_id(student_id):
            raise Exception(f"The student {student_id} already exists!")

        new_student = Student(student_id, name)
        ValidatorStudent.validate(new_student)
        self.students.add(new_student)

    def delete(self, student_id: int) -> None:
        if not self.students.search_id(student_id):
            raise Exception(f"The student {student_id} does not exist!")

        self.students.delete(student_id)

    def modify(self, student_id: int, new_name: str) -> None:
        if not self.students.search_id(student_id):
            raise Exception(f"The student {student_id} does not exist!")

        ValidatorStudent.validate_name(new_name)
        self.students.modify(student_id, new_name)

    def search_id(self, student_id: int) -> str:
        student = self.students.search_id(student_id)

        if not student:
            raise Exception(f"Student {student_id} does not exist!")

        return student

    def search_name(self, student_name: str) -> None:
        student_list = self.students.search_name(student_name)

        if not student_list:
            raise Exception(f"Student '{student_name}' does not exist!")

        return student_list


# /----- Subject -----/


class ManagerSubject:
    def __init__(self, subject_repository: RepoSubject) -> None:
        self.subjects = subject_repository

    def print(self) -> str:
        return self.subjects

    def add(self, subject_id: int, name: str, professor: str) -> None:
        if self.subjects.search_id(subject_id):
            raise Exception(f"The subject {subject_id} already exists!")

        new_subject = Subject(subject_id, name, professor)
        ValidatorSubject.validate(new_subject)
        self.subjects.add(new_subject)

    def delete(self, subject_id: int) -> None:
        if not self.subjects.search_id(subject_id):
            raise Exception(f"The subject {subject_id} does not exist!")

        self.subjects.delete(subject_id)

    def modify(self, subject_id: int, new_name: str, new_professor: str) -> None:
        if not self.subjects.search_id(subject_id):
            raise Exception(f"The subject {subject_id} does not exist!")

        ValidatorSubject.validate_name(new_name)
        ValidatorSubject.validate_prof(new_professor)
        self.subjects.modify(subject_id, new_name, new_professor)

    def search_id(self, subject_id: int) -> tuple:
        subject = self.subjects.search_id(subject_id)

        if not subject:
            raise Exception(f"Subject {subject_id} does not exist!")

        return subject

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


# /----- Grade Book -----/


class ManagerGrade:
    def __init__(
        self,
        grade_book: GradeBook,
        student_repository: RepoStudent,
        subject_repository: RepoSubject,
    ) -> None:
        self.grades = grade_book
        self.students = student_repository
        self.subjects = subject_repository

    def print(self) -> str:
        return self.grades

    def add(
        self, grade_id: int, student_id: int, subject_id: int, value: float
    ) -> None:
        if self.grades.search_id(grade_id):
            raise Exception(f"The grade {grade_id} already exists!")
        if not self.students.search_id(student_id):
            raise Exception(f"The student {student_id} does not exists!")
        if not self.subjects.search_id(subject_id):
            raise Exception(f"The subject {subject_id} does not exists!")

        new_grade = Grade(grade_id, student_id, subject_id, value)
        ValidatorGrade.validate(new_grade)
        self.grades.add(new_grade)

    def delete(self, grade_id: int) -> None:
        if not self.grades.search_id(grade_id):
            raise Exception(f"The grade {grade_id} does not exist!")

        self.grades.delete(grade_id)

    def modify(
        self, grade_id: int, new_student_id: int, new_subject_id: int, new_value: float
    ) -> None:
        if not self.grades.search_id(grade_id):
            raise Exception(f"The grade {grade_id} does not exist!")
        if not self.students.search_id(new_student_id):
            raise Exception(f"The student {new_student_id} does not exists!")
        if not self.subjects.search_id(new_subject_id):
            raise Exception(f"The subject {new_subject_id} does not exists!")

        ValidatorGrade.validate_value(new_value)
        self.grades.modify(grade_id, new_student_id, new_subject_id, new_value)

    def search_id(self, grade_id: int) -> str:
        grade = self.grades.search_id(grade_id)

        if not grade:
            raise Exception(f"Grade {grade_id} does not exist!")

        return grade

    def stats(self, subject_id: int) -> str:
        if not self.subjects.search_id(subject_id):
            raise Exception(f"The subject {subject_id} does not exists!")

        student_dict = {}

        grade_list = self.grades.get_list().values()
        for grade in grade_list:
            if grade.subject_id == subject_id:
                student_dict[self.students.search_id(grade.student_id).name] = grade

        sorted_grades = dict(sorted(student_dict.items())).values()

        output_str = f"\nThe grades in alphabetical order at {self.subjects.search_id(subject_id).name} are:\n"
        output_str += "\n".join(
            [
                f"{self.students.search_id(grade.student_id).name} has an {grade.value}"
                for grade in sorted_grades
            ]
        )

        return output_str

    def stats_ordered(self, subject_id: int) -> str:
        if not self.subjects.search_id(subject_id):
            raise Exception(f"The subject {subject_id} does not exists!")

        grade_list = self.grades.get_list().values()
        sorted_grades = [
            grade for grade in grade_list if grade.subject_id == subject_id
        ]
        sorted_grades = sorted(sorted_grades, key=lambda x: x.value, reverse=True)

        output_str = f"\nThe grades in decreasing order at {self.subjects.search_id(subject_id).name} are:\n"
        output_str += "\n".join(
            [
                f"{self.students.search_id(grade.student_id).name} has an {grade.value}"
                for grade in sorted_grades
            ]
        )

        return output_str

    def top20(self) -> str:
        average = {}
        grade_list = self.grades.get_list().values()

        for grade in grade_list:
            student_id = self.students.search_id(grade.student_id).id
            average[student_id] = average.get(student_id, 0) + grade.value

        for key in average.keys():
            counter = 0
            for grade in grade_list:
                if grade.student_id == key:
                    counter += 1

            average[key] /= counter

        sorted_students = dict(
            sorted(average.items(), key=lambda x: x[1], reverse=True)
        )

        student_list = []
        for key in sorted_students.keys():
            student_list.append(self.students.search_id(key))

        output_str = f"\nThe top 20% of students are:\n"
        output_str += "\n".join(str(student) for student in student_list)

        return output_str
