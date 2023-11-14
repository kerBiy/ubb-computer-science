class Student:
    def __init__(self, id: int, name: str, grades={}) -> None:
        self._id = id
        self._name = name
        self._grades = grades

    def __str__(self) -> str:
        return f"{self.get_id()}. {self.get_name()}\n"

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


class Subject:
    def __init__(self, id: int, name: str, prof: str) -> None:
        self._id = id
        self._name = name
        self._prof = prof

    def __str__(self) -> str:
        return f"{self.get_id()}. {self.get_name()} (professor: {self.get_prof()})\n"

    def get_id(self) -> int:
        return self._id

    def get_name(self) -> str:
        return self._name

    def get_prof(self) -> dict:
        return self._prof

    def set_id(self, new_id: int) -> None:
        self._id = new_id

    def set_name(self, new_name: str) -> None:
        self._name = new_name

    def set_prof(self, new_prof: str) -> None:
        self._prof = new_prof
