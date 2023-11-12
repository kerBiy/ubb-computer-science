# /----- Student -----/


def create_student(_id: int, _name: str, _grades={}) -> list:
    return [_id, _name, _grades]


def get_student_id(student: list) -> int:
    return student[0]


def get_student_name(student: list) -> str:
    return student[1]


def get_student_grades(student: list) -> dict:
    return student[2]


def set_student_id(student: list, new_id: int) -> None:
    student[0] = new_id


def set_student_name(student: list, new_name: str) -> None:
    student[1] = new_name


# /----- Subject -----/


def create_subject(_id: int, _name: str, _prof: str) -> list:
    return [_id, _name, _prof]


def get_subject_id(subject: list) -> int:
    return subject[0]


def get_subject_name(subject: list) -> str:
    return subject[1]


def get_subject_prof(subject: list) -> str:
    return subject[2]


def set_subject_id(subject: list, new_id: int) -> None:
    subject[0] = new_id


def set_subject_name(subject: list, new_name: str) -> None:
    subject[1] = new_name


def set_subject_prof(subject: list, new_prof: str) -> None:
    subject[2] = new_prof
