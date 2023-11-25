from ui.console import Console
from business.manager import ManagerStudent, ManagerSubject, ManagerGrade
from infrastructure.repository import RepoStudent, RepoSubject, GradeBook
from tests.test import test_functions
from tests.random import Random


def main() -> None:
    random_students = Random.students()
    random_subjects = Random.subjects()

    student_repository = RepoStudent(random_students)
    subject_repository = RepoSubject(random_subjects)
    grade_book = GradeBook()

    student_manager = ManagerStudent(student_repository)
    subject_manager = ManagerSubject(subject_repository)
    grade_manager = ManagerGrade(grade_book, student_repository, subject_repository)

    console = Console(student_manager, subject_manager, grade_manager)
    console.run_application()


if __name__ == "__main__":
    test_functions()
    main()
