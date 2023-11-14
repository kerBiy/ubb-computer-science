from infrastructure.domain import Student, Subject


class RepoObject:
    def __init__(self):
        self._list = {}

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
        output = []

        for obj in self._list.values():
            if obj_name in obj.name:
                output.append(obj)

        return output


class RepoStudent(RepoObject):
    def __init__(self) -> None:
        super().__init__()

    def modify(self, obj_id: int, new_name: str) -> None:
        self._list[obj_id] = Student(obj_id, new_name)


class RepoSubject(RepoObject):
    def __init__(self) -> None:
        super().__init__()

    def modify(self, subject_id: int, new_name: str, new_prof: str) -> None:
        self._list[subject_id] = Subject(subject_id, new_name, new_prof)

    def search_prof(self, professor: str) -> list:
        output = []

        for subject in self._list.values():
            if professor in subject.prof:
                output.append(subject)

        return output
