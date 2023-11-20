from domain.domain import Student, Subject, Grade


class RepoObject:
    def __init__(self, object_list):
        self._list = object_list

    def __len__(self):
        return len(self._list)

    def __str__(self):
        if self._list:
            return "\n".join([str(obj) for obj in self._list.values()])

    def add(self, new_obj) -> None:
        self._list[new_obj.id] = new_obj

    def delete(self, obj_id: int) -> None:
        del self._list[obj_id]

    def search_id(self, obj_id: int):
        return self._list.get(obj_id, None)

    def search_name(self, obj_name: str) -> list:
        return [obj for obj in self._list.values() if obj_name in obj.name]


class RepoStudent(RepoObject):
    def __init__(self, student_list={}) -> None:
        super().__init__(student_list)

    def modify(self, obj_id: int, new_name: str) -> None:
        self._list[obj_id] = Student(obj_id, new_name)


class RepoSubject(RepoObject):
    def __init__(self, subject_list={}) -> None:
        super().__init__(subject_list)

    def modify(self, subject_id: int, new_name: str, new_prof: str) -> None:
        self._list[subject_id] = Subject(subject_id, new_name, new_prof)

    def search_prof(self, professor: str) -> list:
        return [subject for subject in self._list.values() if professor in subject.prof]


class GradeBook(RepoObject):
    def __init__(self, grade_list={}) -> None:
        super().__init__(grade_list)

    def modify(
        self,
        grade_id: int,
        new_subject_id: int,
        new_student_id: int,
        new_value: float,
    ) -> None:
        self._list[grade_id] = Grade(
            grade_id, new_subject_id, new_student_id, new_value
        )
