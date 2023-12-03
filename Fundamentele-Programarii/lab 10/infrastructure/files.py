from domain.entity import Student, Subject, Grade


class Files:
    def __init__(self) -> None:
        self.read_from_file = True
        self.memory_students = {}
        self.memory_subjects = {}
        self.memory_grades = {}

        self.student_file_path = "/Users/alexbalta/Developer/School/Fundamentele-Programarii/lab 10/database/studentsDB.txt"
        self.subject_file_path = "/Users/alexbalta/Developer/School/Fundamentele-Programarii/lab 10/database/subjectsDB.txt"
        self.grade_file_path = "/Users/alexbalta/Developer/School/Fundamentele-Programarii/lab 10/database/gradesDB.txt"

    def read_student(self, record_values: list[str]) -> Student:
        return Student(int(record_values[0]), record_values[1])

    def read_subject(self, record_values: list[str]) -> Subject:
        return Subject(int(record_values[0]), record_values[1], record_values[2])

    def read_grade(self, record_values: list[str]) -> Grade:
        return Grade(
            int(record_values[0]),
            int(record_values[1]),
            int(record_values[2]),
            float(record_values[3]),
        )

    def take_db_content(file_path, obj):
        records = {}
        try:
            with open(file_path, "r") as file:
                for line in file:
                    record_values = line.strip().split(",")
                    records[int(record_values[0])] = obj(record_values)
        except FileNotFoundError:
            raise Exception("File Does not exits!")
        return records

    def file_mode(self, students, subjects, grades) -> None:
        self.read_from_file = True
        self.memory_students = students.list
        self.memory_subjects = subjects.list
        self.memory_grades = grades.list

        students.list(self.take_db_content(self.student_file_path, self.read_student))
        subjects.list(self.take_db_content(self.subject_file_path, self.read_subject))
        grades.list(self.take_db_content(self.grade_file_path, self.read_grade))

    def memory_mode(self, students, subjects, grades) -> None:
        self.read_from_file = False
        students.list(self.memory_students)
        subjects.list(self.memory_subjects)
        grades.list(self.memory_grades)

    def change_reade_mode(self, students, subjects, grades) -> None:
        if self.read_from_file:
            self.memory_mode(students, subjects, grades)
        else:
            self.file_mode(students, subjects, grades)
