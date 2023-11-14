from validate.validator import *
from infrastructure.functions import *
from infrastructure.repository import RepoStudent
from infrastructure.domain import Student


# /----- Print -----/


# def manager_print_students(students: list[list]) -> str:
#     return print_students(students)


def manager_print_subjects(subjects: list[list]) -> str:
    return print_subjects(subjects)


# /----- Add -----/


def manager_add_student(students: RepoStudent, student_id: int, name: str) -> None:
    new_student = Student(student_id, name)
    validate_student(new_student)
    students.add_student(new_student)


def manager_add_subject(
    subjects: list[list], subject_id: int, name: str, prof: str
) -> None:
    new_subject = create_subject(subject_id, name, prof)
    validate_subject(new_subject)
    add_subject(subjects, new_subject)


# /----- Delete -----/


def manager_delete_student(students: RepoStudent, student_id: int) -> None:
    if not students.search_student_by_id(student_id):
        raise Exception(f"The student {student_id} does not exist!")

    validate_student_id(student_id)
    students.delete_student(student_id)


def manager_delete_subject(subjects: list[list], subject_id: int) -> None:
    if not search_subject_by_id(subjects, subject_id):
        raise Exception(f"The subject {subject_id} does not exist!")

    validate_subject_id(subject_id)
    delete_subject(subjects, subject_id)


# /----- Modify -----/


def manager_modify_student(
    students: list[list], student_id: int, new_name: str
) -> None:
    if not students.search_student_by_id(student_id):
        raise Exception(f"The student {student_id} does not exist!")

    validate_student_name(new_name)
    students.modify_student(student_id, new_name)


def manager_modify_subject(
    subjects: list[list], subject_id: int, new_name: str, new_professor: str
) -> None:
    if not search_subject_by_id(subjects, subject_id):
        raise Exception(f"The subject {subject_id} does not exist!")

    validate_subject_name(new_name)
    validate_subject_prof(new_professor)
    modify_subject(subjects, subject_id, new_name, new_professor)


# /----- Searching -----/


def manager_search_student_by_id(students: list[list], student_id: int) -> str:
    student = students.search_student_by_id(student_id)

    if not student:
        raise Exception(f"Student {student_id} does not exist!")

    return student.get_name()


def manager_search_subject_by_id(subjects: list[list], subject_id: int) -> tuple:
    subject = search_subject_by_id(subjects, subject_id)

    if not subject:
        raise Exception(f"Subject {subject_id} does not exist!")

    return get_subject_name(subject), get_subject_prof(subject)


def manager_search_student_by_name(students: list[list], student_name: str) -> None:
    student_list = students.search_student_by_name(student_name)

    if not student_list:
        raise Exception(f"Student '{student_name}' does not exist!")

    return student_list


def manager_search_subject_by_name(subjects: list[list], subject_name: str) -> None:
    subject_list = search_subject_by_name(subjects, subject_name)

    if not subject_list:
        raise Exception(f"Subject '{subject_name}' does not exist!")

    return subject_list


def manager_search_subject_by_prof(subjects: list[list], prof: str) -> None:
    subject_list = search_subject_by_prof(subjects, prof)

    if not subject_list:
        raise Exception(f"Professor '{prof}' does not exist!")

    return subject_list
