class RepoStudent:
    def __init__(self):
        self._student_list = []

    def __len__(self):
        return len(self._student_list)

    def __str__(self):
        output = ""

        for student in self._student_list:
            output += str(student)

        return output[-1]

    def add(self, new_student) -> None:
        self._student_list.append(new_student)

    def delete(self, student_id: int) -> None:
        for ind, student in enumerate(self._student_list):
            if student.id == student_id:
                self._student_list.pop(ind)

    def modify(self, student_id: int, new_name: str) -> None:
        for ind, student in enumerate(self._student_list):
            if student.id == student_id:
                self._student_list[ind].set_name(new_name)

    def search_by_id(self, student_id: int):
        for student in self._student_list:
            if student.id == student_id:
                return student
        return None

    def search_by_name(self, student_name: str) -> list:
        output = []

        for student in self._student_list:
            if student_name in student.name:
                output.append(student)

        return output


class RepoSubject:
    def __init__(self):
        self._subject_list = []

    def __len__(self):
        return len(self._subject_list)

    def __str__(self):
        output = ""

        for subject in self._subject_list:
            output += str(subject)

        return output[-1]

    def add(self, new_subject) -> None:
        self._subject_list.append(new_subject)

    def delete(self, subject_id: int) -> None:
        for ind, subject in enumerate(self._subject_list):
            if subject.id == subject_id:
                self._subject_list.pop(ind)

    def modify(self, subject_id: int, new_name: str, new_prof: str) -> None:
        for ind, subject in enumerate(self._subject_list):
            if subject.id == subject_id:
                self._subject_list[ind].set_name(new_name)
                self._subject_list[ind].set_prof(new_prof)

    def search_by_id(self, subject_id: int):
        for subject in self._subject_list:
            if subject.id == subject_id:
                return subject
        return None

    def search_by_name(self, subject_name: str) -> list:
        output = []

        for subject in self._subject_list:
            if subject_name in subject.name:
                output.append(subject)

        return output

    def search_by_prof(self, professor: str) -> list:
        output = []

        for subject in self._subject_list:
            if professor in subject.prof:
                output.append(subject)

        return output
