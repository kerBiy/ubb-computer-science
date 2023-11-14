class Object:
    def __init__(self, id: int, name: str) -> None:
        self._id = id
        self._name = name

    def __str__(self) -> str:
        return f"{self.id}. {self.name}\n"

    @property
    def id(self) -> int:
        return self._id

    @property
    def name(self) -> str:
        return self._name

    @id.setter
    def id(self, new_id: int) -> None:
        self._id = new_id

    @name.setter
    def name(self, new_name: str) -> None:
        self._name = new_name


class Student(Object):
    def __init__(self, id: int, name: str, grades={}) -> None:
        super().__init__(id, name)
        self._grades = grades

    @property
    def grades(self):
        return self._grades

    @grades.setter
    def grades(self, new_grades) -> None:
        self._grades = new_grades


class Subject(Object):
    def __init__(self, id: int, name: str, prof: str) -> None:
        super().__init__(id, name)
        self._prof = prof

    def __str__(self) -> str:
        return f"{self.id}. {self.name} (professor: {self.prof})\n"

    @property
    def prof(self) -> str:
        return self._prof

    @prof.setter
    def prof(self, new_prof: str) -> None:
        self._prof = new_prof
