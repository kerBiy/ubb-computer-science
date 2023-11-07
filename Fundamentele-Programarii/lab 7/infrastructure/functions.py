from infrastructure.domain import *


def add_student(students: list[list], new_student: list) -> None:
    students.append(new_student)


def delete_student(students: list[list], student_id: int) -> None:
    for ind, student in enumerate(students):
        if get_student_id(student) == student_id:
            students.pop(ind)


def modify_student(students: list[list], student_id: int, new_name: str) -> None:
    for ind, student in enumerate(students):
        if get_student_id(student) == student_id:
            set_student_name(students[ind], new_name)


# /----- Subject -----/


def add_subject(subjects: list[list], new_subject: list) -> None:
    subjects.append(new_subject)


def delete_subject(subjects: list[list], subject_id: int) -> None:
    for ind, subject in enumerate(subjects):
        if get_subject_id(subject) == subject_id:
            subjects.pop(ind)


def modify_subject(
    subjects: list[list], subject_id: int, new_name: str, new_professor: str
) -> None:
    for ind, subject in enumerate(subjects):
        if get_subject_id(subject) == subject_id:
            set_subject_name(subjects[ind], new_name)
            set_subject_prof(subjects[ind], new_professor)


# /----- Searching -----/


def search_student_by_id(students: list[list], student_id: int) -> list:
    for ind, student in enumerate(students):
        if get_student_id(student) == student_id:
            return student
    return None


def search_student_by_name(students: list[list], name: str) -> list:
    for ind, student in enumerate(students):
        if get_student_name(student) == name:
            return student
    return None


def search_subject_by_id(subjects: list[list], subject_id: int) -> list:
    for ind, subject in enumerate(subjects):
        if get_subject_id(subject) == subject_id:
            return subject
    return None


def search_subject_by_name(subjects: list[list], name: str) -> list:
    for ind, subject in enumerate(subjects):
        if get_subject_name(subject) == name:
            return subject
    return None


# /----- Add Grade -----/
