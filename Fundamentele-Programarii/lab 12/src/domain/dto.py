from domain.entity import Student, Subject, Grade


class GradeDTO:
    def __init__(
        self, grade_id: int, student: Student, subject: Subject, value: float
    ) -> None:
        self.__id = grade_id
        self.__student = student
        self.__subject = subject
        self.__value = value

    def __str__(self) -> str:
        return (
            f"{self.id}: {self.student.name} has an {self.value} at {self.subject.name}"
        )

    @property
    def id(self) -> int:
        return self.__id

    @property
    def student(self) -> Student:
        return self.__student

    @property
    def subject(self) -> Subject:
        return self.__subject

    @property
    def value(self) -> float:
        return self.__value


class StudentDTO:
    def __init__(
        self, student_id: int, student_name: str, grade_list: list[Grade]
    ) -> None:
        self.__id = student_id
        self.__name = student_name
        self.__grades = grade_list

    def __str__(self) -> str:
        return f"{self.id}: {self.name} has an average of {self.average}, {self.lowest_grade}"

    @property
    def id(self) -> int:
        return self.__id

    @property
    def name(self) -> str:
        return self.__name

    @property
    def grades(self) -> list[Grade]:
        return self.__grades

    @property
    def average(self) -> float:
        grades_sum = 0
        for grade in self.grades:
            grades_sum += grade.value

        return grades_sum / len(self.grades)

    @property
    def lowest_grade(self) -> float:
        return min(self.grades, key=lambda x: x.value).value
