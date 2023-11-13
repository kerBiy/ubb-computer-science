from infrastructure.domain import *


def validate_name(name: str) -> bool:
    name_list = name.split()

    if not (2 <= len(name_list) <= 5):
        return False

    for name in name_list:
        if not (name[0].isupper() and name[1:].isalpha() and name[1:].islower()):
            return False

    return True


def validate_student(student: list) -> None:
    error = ""

    if not validate_student_id(get_student_id(student)):
        error += "Invalid student id number.\n"
    if not validate_student_name(get_student_name(student)):
        error += "Invalid student name.\n"
    if not validate_student_grades(get_student_grades(student)):
        error += "Invalid student grades.\n"

    if error:
        raise ValueError(error[:-2])


def validate_student_id(student_id: int) -> bool:
    return 1 <= student_id <= 9999


def validate_student_name(student_name: str) -> bool:
    return validate_name(student_name)


def validate_student_grades(grades: dict) -> bool:
    for grade in grades.values():
        if not (1 <= grade <= 10):
            return False

    return True


# /----- Subjects -----/


def validate_subject(subject: list) -> None:
    error = ""

    if not validate_subject_id(get_subject_id(subject)):
        error += "Invalid subject id number.\n"
    if not validate_subject_name(get_subject_name(subject)):
        error += "Invalid subject name.\n"
    if not validate_subject_prof(get_subject_prof(subject)):
        error += "Invalid subject professor.\n"

    if error:
        raise ValueError(error[:-2])


def validate_subject_id(subject_id: int) -> bool:
    return 1 <= subject_id <= 99999


def validate_subject_name(subject_name: str) -> bool:
    if not (1 <= len(subject_name.split()) <= 8):
        return False

    return subject_name[0].isupper()


def validate_subject_prof(professor: str) -> bool:
    return validate_name(professor)
