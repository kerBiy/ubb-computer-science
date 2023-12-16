class Student:
    def __init__(self, id: int, name: str) -> None:
        self.__id = id
        self.__name = name

    def __str__(self) -> str:
        return f"{self.id}. {self.name}"

    def __eq__(self, another_student: object) -> bool:
        return (
            isinstance(another_student, Student)
            and self.id == another_student.id
            and self.name == another_student.name
        )

    @property
    def id(self) -> int:
        return self.__id

    @property
    def name(self) -> str:
        return self.__name

    @name.setter
    def name(self, new_name: str) -> None:
        self.__name = new_name


class Subject:
    def __init__(self, id: int, name: str, prof: str) -> None:
        self.__id = id
        self.__name = name
        self.__prof = prof

    def __str__(self) -> str:
        return f"{self.id}. {self.name} (professor: {self.prof})"

    def __eq__(self, another_subject: object) -> bool:
        return (
            isinstance(another_subject, Subject)
            and self.id == another_subject.id
            and self.name == another_subject.name
            and self.prof == another_subject.prof
        )

    @property
    def id(self) -> int:
        return self.__id

    @property
    def name(self) -> str:
        return self.__name

    @name.setter
    def name(self, new_name: str) -> None:
        self.__name = new_name

    @property
    def prof(self) -> str:
        return self.__prof

    @prof.setter
    def prof(self, new_prof: str) -> None:
        self.__prof = new_prof


class Grade:
    def __init__(
        self, grade_id: int, student_id: int, subject_id: int, value: float
    ) -> None:
        self.__id = grade_id
        self.__student_id = student_id
        self.__subject_id = subject_id
        self.__value = value

    def __str__(self) -> str:
        return f"{self.id}: Student {self.student_id} has an {self.value} at Subject {self.subject_id}"

    def __eq__(self, another_grade: object) -> bool:
        return (
            isinstance(another_grade, Grade)
            and self.id == another_grade.id
            and self.student_id == another_grade.student_id
            and self.subject_id == another_grade.subject_id
            and self.value == another_grade.value
        )

    @property
    def id(self) -> int:
        return self.__id

    @property
    def student_id(self) -> int:
        return self.__student_id

    @property
    def subject_id(self) -> int:
        return self.__subject_id

    @property
    def value(self) -> float:
        return self.__value
