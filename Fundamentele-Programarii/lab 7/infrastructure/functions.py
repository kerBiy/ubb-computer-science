from infrastructure.domain import *

# /----- Print -----/


def print_students(students: list[list]) -> str:
    output = ""

    for student in students:
        output += f"{get_student_id(student)}. {get_student_name(student)}\n"

    return output[:-1]


def print_subjects(subjects: list[list]) -> None:
    output = ""

    for subject in subjects:
        output += f"{get_subject_id(subject)}. {get_subject_name(subject)} (professor: {get_subject_prof(subject)})\n"

    return output[:-1]


# /----- Add -----/


def add_student(students: list[list], new_student: list) -> None:
    students.append(new_student)


def add_subject(subjects: list[list], new_subject: list) -> None:
    subjects.append(new_subject)


# /----- Delete -----/


def delete_student(students: list[list], student_id: int) -> None:
    for ind, student in enumerate(students):
        if get_student_id(student) == student_id:
            students.pop(ind)


def delete_subject(subjects: list[list], subject_id: int) -> None:
    for ind, subject in enumerate(subjects):
        if get_subject_id(subject) == subject_id:
            subjects.pop(ind)


# /----- Modify -----/


def modify_student(students: list[list], student_id: int, new_name: str) -> None:
    for ind, student in enumerate(students):
        if get_student_id(student) == student_id:
            set_student_name(students[ind], new_name)


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


def search_subject_by_id(subjects: list[list], subject_id: int) -> list:
    for ind, subject in enumerate(subjects):
        if get_subject_id(subject) == subject_id:
            return subject
    return None


def search_student_by_name(students: list[list], student_name: str) -> list[list]:
    output = []

    for ind, student in enumerate(students):
        if student_name in get_student_name(student):
            output.append(student)

    return output


def search_subject_by_name(subjects: list[list], subject_name: str) -> list[list]:
    output = []

    for ind, subject in enumerate(subjects):
        if subject_name in get_subject_name(subject):
            output.append(subject)

    return output


def search_subject_by_prof(subjects: list[list], prof: str) -> list[list]:
    output = []

    for ind, subject in enumerate(subjects):
        if prof in get_subject_prof(subject):
            output.append(subject)

    return output


# /----- Add Grade -----/
