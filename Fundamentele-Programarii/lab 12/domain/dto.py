from domain.entity import Student, Subject


class GradeAssembler:
    @staticmethod
    def create_grade_dto(id: int, student: Student, subject: Subject, grade):
        return GradeDTO(id, student.name, subject.name, grade)


class GradeDTO:
    def __init__(
        self, grade_id: int, student_name: str, subject_name: str, value: float
    ) -> None:
        self.__id = grade_id
        self.__student_name = student_name
        self.__subject_name = subject_name
        self.__value = value

    def __str__(self) -> str:
        return f"{self.id}: Student {self.student_name} has an {self.value} at Subject {self.subject_name}"

    @property
    def id(self) -> int:
        return self.__id

    @property
    def student_name(self) -> str:
        return self.__student_name

    @property
    def subject_name(self) -> str:
        return self.__subject_name

    @property
    def value(self) -> float:
        return self.__value
