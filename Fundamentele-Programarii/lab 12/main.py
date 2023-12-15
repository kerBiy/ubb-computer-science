from infrastructure.fileRepository import (
    StudentFileRepository,
    SubjectFileRepository,
    GradeFileRepository,
)
from business.manager import ManagerStudent, ManagerSubject, ManagerGrade
from ui.console import Console
from tests.test import Test


class App:
    @staticmethod
    def main() -> None:
        student_repository = StudentFileRepository("database/studentsDB.txt")
        student_manager = ManagerStudent(student_repository)

        subject_repository = SubjectFileRepository("database/subjectsDB.txt")
        subject_manager = ManagerSubject(subject_repository)

        grade_book = GradeFileRepository("database/gradesDB.txt")
        grade_manager = ManagerGrade(grade_book, student_repository, subject_repository)

        console = Console(student_manager, subject_manager, grade_manager)
        console.run_application()


if __name__ == "__main__":
    Test.run_tests()
    App.main()
