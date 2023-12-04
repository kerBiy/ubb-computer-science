from domain.entity import Student, Subject, Grade


class RepoStudent:
    def __init__(self, student_list=None):
        if not student_list:
            self._list = {}
        else:
            self._list = student_list

    def __len__(self):
        return len(self._list)

    def __str__(self):
        return "\n".join([str(student) for student in self._list.values()])

    def __eq__(self, another_repo) -> bool:
        return self._list == another_repo._list

    @property
    def list(self) -> dict:
        return self._list

    @list.setter
    def list(self, another_list) -> None:
        self._list = another_list

    def add(self, new_student: Student) -> None:
        self._list[new_student.id] = new_student

    def delete(self, student_id: int) -> None:
        del self._list[student_id]

    def modify(self, student_id: int, new_name: str) -> None:
        self._list[student_id] = Student(student_id, new_name)

    def search_id(self, student_id: int):
        return self._list.get(student_id, None)

    def search_name(self, student_name: str) -> list:
        return [
            student for student in self._list.values() if student_name in student.name
        ]


class RepoSubject:
    def __init__(self, subject_list=None):
        if not subject_list:
            self._list = {}
        else:
            self._list = subject_list

    def __len__(self):
        return len(self._list)

    def __str__(self):
        if self._list:
            return "\n".join([str(subject) for subject in self._list.values()])

    def __eq__(self, another_repo) -> bool:
        return self._list == another_repo._list

    @property
    def list(self) -> dict:
        return self._list

    @list.setter
    def list(self, another_list) -> None:
        self._list = another_list

    def add(self, new_subject: Subject) -> None:
        self._list[new_subject.id] = new_subject

    def delete(self, subject_id: int) -> None:
        del self._list[subject_id]

    def modify(self, subject_id: int, new_name: str, new_prof: str) -> None:
        self._list[subject_id] = Subject(subject_id, new_name, new_prof)

    def search_id(self, subject_id: int):
        return self._list.get(subject_id, None)

    def search_name(self, subject_name: str) -> list:
        return [
            subject for subject in self._list.values() if subject_name in subject.name
        ]

    def search_prof(self, professor: str) -> list:
        return [subject for subject in self._list.values() if professor in subject.prof]


class GradeBook:
    def __init__(self, grade_list=None):
        if not grade_list:
            self._list = {}
        else:
            self._list = grade_list

    def __len__(self):
        return len(self._list)

    def __str__(self):
        if self._list:
            return "\n".join([str(grade) for grade in self._list.values()])

    def __eq__(self, another_repo) -> bool:
        return self._list == another_repo._list

    @property
    def list(self) -> dict:
        return self._list

    @list.setter
    def list(self, another_list) -> None:
        self._list = another_list

    def add(self, new_grade: Grade) -> None:
        self._list[new_grade.id] = new_grade

    def delete(self, grade_id: int) -> None:
        del self._list[grade_id]

    def search_id(self, grade_id: int):
        return self._list.get(grade_id, None)
