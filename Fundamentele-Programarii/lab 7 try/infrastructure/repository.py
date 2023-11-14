# from infrastructure.repository import Student


class RepoStudent:
    def __init__(self):
        self._student_list = []

    def get_len(self):
        return len(self._student_list)

    def add_student(self, new_student) -> None:
        self._student_list.append(new_student)

    def delete_student(self, student_id: int) -> None:
        for ind, student in enumerate(self._student_list):
            if student.get_id() == student_id:
                self._student_list.pop(ind)

    def modify_student(self, student_id: int, new_name: str) -> None:
        for ind, student in enumerate(self._student_list):
            if student.get_id() == student_id:
                self._student_list[ind].set_name(new_name)

    def search_student_by_id(self, student_id: int):
        for student in self._student_list:
            if student.get_id() == student_id:
                return student
        return None

    def search_student_by_name(self, student_name: str) -> list:
        output = []

        for student in self._student_list:
            if student_name in student.get_name():
                output.append(student)

        return output

    def print_students(self) -> str:
        output = ""
        for student in self._student_list:
            output += f"{student.get_id()}. {student.get_name()}\n"

        print(output[-1])
