# /----- Student -----/


class Student:
    def __init__(self, id: int, name: str, grades={}) -> None:
        self._id = id
        self._name = name
        self._grades = grades

    def get_id(self) -> int:
        return self._id

    def get_name(self) -> str:
        return self._name

    def get_grades(self) -> dict:
        return self._grades

    def set_id(self, new_id: int) -> None:
        self._id = new_id

    def set_name(self, new_name: str) -> None:
        self._name = new_name


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
