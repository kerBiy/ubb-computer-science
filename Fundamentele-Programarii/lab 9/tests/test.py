from infrastructure.repository import *


# /----- Add -----/


def test_add_student() -> None:
    new_student_repo = RepoStudent()
    correct_student_repo = RepoStudent({112: Student(112, "James Bond")})
    new_student = Student(112, "James Bond")

    new_student_repo.add(new_student)

    assert new_student_repo == correct_student_repo


def test_add_subject() -> None:
    new_subject_repo = RepoSubject()
    correct_subject_repo = RepoSubject(
        {112: Subject(112, "Advanced Calculus", "James Bond")}
    )
    new_subject = Subject(112, "Advanced Calculus", "James Bond")

    new_subject_repo.add(new_subject)

    assert new_subject_repo == correct_subject_repo


def test_add_grade() -> None:
    new_grade_repo = GradeBook()
    correct_grade_repo = GradeBook({112: Grade(112, 234, 345, 7.5)})
    new_grade = Grade(112, 234, 345, 7.5)

    new_grade_repo.add(new_grade)

    assert new_grade_repo == correct_grade_repo


# /----- Delete -----/


def test_delete_student() -> None:
    new_student_repo = RepoStudent(
        {
            111: Student(111, "Sergio Ramos"),
            112: Student(112, "James Bond"),
            113: Student(113, "Jack The Ripper"),
            212: Student(212, "John Wick"),
        }
    )

    correct_student_repo = RepoStudent(
        {
            111: Student(111, "Sergio Ramos"),
            113: Student(113, "Jack The Ripper"),
            212: Student(212, "John Wick"),
        }
    )
    student_id = 112

    new_student_repo.delete(student_id)

    assert new_student_repo == correct_student_repo


def test_delete_subject() -> None:
    new_subject_repo = RepoSubject(
        {
            111: Subject(111, "Special Maths", "Sergio Ramos"),
            112: Subject(112, "Calculus", "James Bond"),
            113: Subject(113, "Algebra", "Jack The Ripper"),
            212: Subject(212, "Geometry", "John Wick"),
        }
    )

    correct_subject_repo = RepoSubject(
        {
            111: Subject(111, "Special Maths", "Sergio Ramos"),
            113: Subject(113, "Algebra", "Jack The Ripper"),
            212: Subject(212, "Geometry", "John Wick"),
        }
    )
    subject_id = 112

    new_subject_repo.delete(subject_id)

    assert new_subject_repo == correct_subject_repo


# # /----- Modify -----/


# def test_modify_student() -> None:
#     new_student_list = [[112, "Sergio Ramos"]]
#     correct_student_list = [[112, "James Bond"]]

#     student_id = 112
#     new_name = "James Bond"

#     modify_student(new_student_list, student_id, new_name)

#     assert new_student_list == correct_student_list


# def test_modify_subject() -> None:
#     new_subject_list = [[112, "Algebra", "Sergio Ramos"]]
#     correct_subject_list = [[112, "Calculus", "James Bond"]]

#     subject_id = 112
#     new_name = "Calculus"
#     new_prof = "James Bond"

#     modify_subject(new_subject_list, subject_id, new_name, new_prof)

#     assert new_subject_list == correct_subject_list


# # /----- Search -----/


# def test_search_id() -> None:
#     student_list = {
#         111: Student(111, "Sergio Ramos"),
#         112: Student(112, "James Bond"),
#         113: Student(113, "Jack The Ripper"),
#         212: Student(212, "John Wick"),
#     }

#     correct_student = Student(113, "Jack The Ripper")

#     student_id = 113
#     student_list.search_id(student_id)

#     assert student_list == correct_student


# def test_search_subject_by_id() -> None:
#     subject_list = [
#         [111, "Special Maths", "Sergio Ramos"],
#         [112, "Calculus", "James Bond"],
#         [113, "Algebra", "Jack The Ripper"],
#         [212, "Geometry", "John Wick"],
#     ]
#     correct_subject = [113, "Algebra", "Jack The Ripper"]

#     subject_id = 113
#     answer = search_subject_by_id(subject_list, subject_id)

#     assert answer == correct_subject


# def test_search_name() -> None:
#     student_list = [
#         [111, "Sergio John"],
#         [112, "James Bond"],
#         [113, "Jack The Ripper"],
#         [212, "John Wick"],
#     ]
#     correct_student_list = [
#         [111, "Sergio John"],
#         [212, "John Wick"],
#     ]

#     student_name = "John"
#     answer = search_name(student_list, student_name)

#     assert answer == correct_student_list


# def test_search_subject_by_name() -> None:
#     subject_list = [
#         [111, "Special Maths", "Sergio Ramos"],
#         [112, "Calculus", "James Bond"],
#         [113, "Algebra", "Jack The Ripper"],
#         [212, "Mathematic", "John Wick"],
#     ]
#     correct_subject_list = [
#         [111, "Special Maths", "Sergio Ramos"],
#         [212, "Mathematic", "John Wick"],
#     ]

#     subject_name = "Math"
#     answer = search_subject_by_name(subject_list, subject_name)

#     assert answer == correct_subject_list


# def test_search_subject_by_prof() -> None:
#     subject_list = [
#         [111, "Special Maths", "Sergio Jack"],
#         [112, "Calculus", "James Bond"],
#         [113, "Algebra", "Jack The Ripper"],
#         [212, "Mathematic", "John Wick"],
#     ]
#     correct_subject_list = [
#         [111, "Special Maths", "Sergio Jack"],
#         [113, "Algebra", "Jack The Ripper"],
#     ]

#     subject_prof = "Jack"
#     answer = search_subject_by_prof(subject_list, subject_prof)

#     assert answer == correct_subject_list


def test_stats() -> None:
    pass


def test_stats_ordered() -> None:
    pass


def test_top20() -> None:
    pass


def test_functions() -> None:
    test_add_student()
    test_add_subject()
    test_add_grade()
    test_delete_student()
    test_delete_subject()
    # test_delete_grade()
    # test_modify_student()
    # test_modify_subject()
    # test_search_id()
    # test_search_subject_by_id()
    # test_search_name()
    # test_search_subject_by_name()
    # test_search_subject_by_prof()

    test_stats()
    test_stats_ordered()
    test_top20()

    print("All tests passed!")
