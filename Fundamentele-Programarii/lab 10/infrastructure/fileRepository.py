from infrastructure.repository import RepoStudent, Student


class FileStudentRepo(RepoStudent):
    def __init__(self, file_name: str, student_list: dict = None):
        super().__init__(student_list)
        self.__file_name = file_name
        self.load_students()

    def save(self, item):
        self.add(item)
        self.save_student(item)

    def load_students(self):
        try:
            with open(self.__file_name, "r") as file:
                for line in file:
                    record = line.strip().split(",")
                    new_student = Student(int(record[0]), record[1])
                    self.add(new_student)

        except Exception as ex:
            print(ex)

    def save_student(self, student: Student):
        try:
            with open(self.__file_name, "a") as file:
                new_line = f"{str(student.id)},{student.name}\n"
                file.write(new_line)
        except Exception as ex:
            raise Exception(ex)
