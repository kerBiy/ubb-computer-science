from validate.validator import validate_student, validate_subject
from infrastructure.functions import *

# /----- Add -----/


def manager_add_student(students: list[list], student_id: int, name: str) -> None:
    new_student = create_student(students, student_id, name)
    validate_student(new_student, students)
    add_student(students, new_student)


def manager_add_subject(
    subjects: list[list], subject_id: int, name: str, prof: str
) -> None:
    new_subject = create_subject(subject_id, name, prof)
    validate_subject(new_subject)
    add_subject(subjects, new_subject)


# /----- Delete -----/


def manager_delete_student(students: list[list], student_id: int) -> None:
    pass


def manager_delete_subject(subjects: list[list], subject_id: int) -> None:
    pass


# /----- Modify -----/


def manager_modify_student(
    students: list[list], student_id: int, new_name: str
) -> None:
    pass


def manager_modify_subject(
    subjects: list[list], subject_id: int, new_name: str, new_professor: str
) -> None:
    pass


# /----- Searching -----/


def manager_search_student_by_id(students: list[list], student_id: int) -> None:
    pass


def manager_search_student_by_name(students: list[list], name: str) -> None:
    pass


def manager_search_subject_by_id(subjects: list[list], subject_id: int) -> None:
    pass


def manager_search_subject_by_name(subjects: list[list], name: str) -> None:
    pass
