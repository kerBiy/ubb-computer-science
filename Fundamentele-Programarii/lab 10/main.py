from ui.console import Console
from business.manager import ManagerStudent, ManagerSubject, ManagerGrade, ManagerStats
from infrastructure.repository import RepoStudent, RepoSubject, GradeBook
from tests.test import test_functions
from tests.random import Random


def main() -> None:
    students_list = Random.set_students()
    subjects_list = Random.set_subjects()
    grades_list = Random.set_grades()

    student_repository = RepoStudent(students_list)
    subject_repository = RepoSubject(subjects_list)
    grade_book = GradeBook(grades_list)

    student_manager = ManagerStudent(student_repository)
    subject_manager = ManagerSubject(subject_repository)
    grade_manager = ManagerGrade(grade_book, student_repository, subject_repository)
    stats_manager = ManagerStats(student_repository, subject_repository, grade_book)

    console = Console(student_manager, subject_manager, grade_manager, stats_manager)
    console.run_application()


if __name__ == "__main__":
    test_functions()
    main()
