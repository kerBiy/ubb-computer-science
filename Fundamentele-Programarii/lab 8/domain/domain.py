class Object:
    def __init__(self, id: int, name: str) -> None:
        self._id = id
        self._name = name

    def __str__(self) -> str:
        return f"{self._id}. {self._name}"

    @property
    def id(self) -> int:
        return self._id

    @id.setter
    def id(self, new_id: int) -> None:
        self._id = new_id

    @property
    def name(self) -> str:
        return self._name

    @name.setter
    def name(self, new_name: str) -> None:
        self._name = new_name


class Student(Object):
    def __init__(self, id: int, name: str) -> None:
        super().__init__(id, name)


class Subject(Object):
    def __init__(self, id: int, name: str, prof: str) -> None:
        super().__init__(id, name)
        self._prof = prof

    def __str__(self) -> str:
        return f"{self.id}. {self.name} (professor: {self.prof})"

    @property
    def prof(self) -> str:
        return self._prof

    @prof.setter
    def prof(self, new_prof: str) -> None:
        self._prof = new_prof


class Grade:
    def __init__(
        self, grade_id: int, student_id: int, subject_id: int, value: float
    ) -> None:
        self._id = grade_id
        self._student_id = student_id
        self._subject_id = subject_id
        self._value = value

    def __str__(self) -> str:
        return f"{self.id}: Student {self.student_id} has an {self.value} at Subject {self.subject_id}"

    @property
    def id(self) -> int:
        return self._id

    @id.setter
    def id(self, new_id: int) -> None:
        self._id = new_id

    @property
    def student_id(self) -> int:
        return self.student_id

    @student_id.setter
    def student_id(self, student_id: int) -> None:
        self.student_id = student_id

    @property
    def subject_id(self) -> int:
        return self._subject_id

    @subject_id.setter
    def subject_id(self, new_subject_id: int) -> None:
        self._subject_id = new_subject_id

    @property
    def value(self) -> float:
        return self._value

    @value.setter
    def value(self, new_value: float) -> None:
        self._value = new_value
