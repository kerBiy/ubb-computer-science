from infrastructure.functions import *


# /----- Add -----/


def test_add_student() -> None:
    new_student_list = []
    correct_student_list = [[112, "James Bond"]]
    new_student = [112, "James Bond"]

    add_student(new_student_list, new_student)

    assert new_student_list == correct_student_list


def test_add_subject() -> None:
    new_subject_list = []
    correct_subject_list = [[112, "Calculus", "James Bond"]]
    new_subject = [112, "Calculus", "James Bond"]

    add_subject(new_subject_list, new_subject)

    assert new_subject_list == correct_subject_list


# /----- Delete -----/


def test_delete_student() -> None:
    new_student_list = [
        [111, "Sergio Ramos"],
        [112, "James Bond"],
        [113, "Jack The Ripper"],
        [212, "John Wick"],
    ]
    correct_student_list = [
        [111, "Sergio Ramos"],
        [113, "Jack The Ripper"],
        [212, "John Wick"],
    ]
    student_id = 112

    delete_student(new_student_list, student_id)

    assert new_student_list == correct_student_list


def test_delete_subject() -> None:
    new_subject_list = [
        [111, "Special Maths", "Sergio Ramos"],
        [112, "Calculus", "James Bond"],
        [113, "Algebra", "Jack The Ripper"],
        [212, "Geometry", "John Wick"],
    ]
    correct_subject_list = [
        [111, "Special Maths", "Sergio Ramos"],
        [113, "Algebra", "Jack The Ripper"],
        [212, "Geometry", "John Wick"],
    ]
    subject_id = 112

    delete_subject(new_subject_list, subject_id)

    assert new_subject_list == correct_subject_list


# /----- Modify -----/


def test_modify_student() -> None:
    new_student_list = [[112, "Sergio Ramos"]]
    correct_student_list = [[112, "James Bond"]]

    student_id = 112
    new_name = "James Bond"

    modify_student(new_student_list, student_id, new_name)

    assert new_student_list == correct_student_list


def test_modify_subject() -> None:
    new_subject_list = [[112, "Algebra", "Sergio Ramos"]]
    correct_subject_list = [[112, "Calculus", "James Bond"]]

    subject_id = 112
    new_name = "Calculus"
    new_prof = "James Bond"

    modify_subject(new_subject_list, subject_id, new_name, new_prof)

    assert new_subject_list == correct_subject_list


# /----- Search -----/


def test_search_student_by_id() -> None:
    student_list = [
        [111, "Sergio Ramos"],
        [112, "James Bond"],
        [113, "Jack The Ripper"],
        [212, "John Wick"],
    ]
    correct_student = [113, "Jack The Ripper"]

    student_id = 113
    answer = search_student_by_id(student_list, student_id)

    assert answer == correct_student


def test_search_subject_by_id() -> None:
    subject_list = [
        [111, "Special Maths", "Sergio Ramos"],
        [112, "Calculus", "James Bond"],
        [113, "Algebra", "Jack The Ripper"],
        [212, "Geometry", "John Wick"],
    ]
    correct_subject = [113, "Algebra", "Jack The Ripper"]

    subject_id = 113
    answer = search_subject_by_id(subject_list, subject_id)

    assert answer == correct_subject


def test_search_student_by_name() -> None:
    student_list = [
        [111, "Sergio John"],
        [112, "James Bond"],
        [113, "Jack The Ripper"],
        [212, "John Wick"],
    ]
    correct_student_list = [
        [111, "Sergio John"],
        [212, "John Wick"],
    ]

    student_name = "John"
    answer = search_student_by_name(student_list, student_name)

    assert answer == correct_student_list


def test_search_subject_by_name() -> None:
    subject_list = [
        [111, "Special Maths", "Sergio Ramos"],
        [112, "Calculus", "James Bond"],
        [113, "Algebra", "Jack The Ripper"],
        [212, "Mathematic", "John Wick"],
    ]
    correct_subject_list = [
        [111, "Special Maths", "Sergio Ramos"],
        [212, "Mathematic", "John Wick"],
    ]

    subject_name = "Math"
    answer = search_subject_by_name(subject_list, subject_name)

    assert answer == correct_subject_list


def test_search_subject_by_prof() -> None:
    subject_list = [
        [111, "Special Maths", "Sergio Jack"],
        [112, "Calculus", "James Bond"],
        [113, "Algebra", "Jack The Ripper"],
        [212, "Mathematic", "John Wick"],
    ]
    correct_subject_list = [
        [111, "Special Maths", "Sergio Jack"],
        [113, "Algebra", "Jack The Ripper"],
    ]

    subject_prof = "Jack"
    answer = search_subject_by_prof(subject_list, subject_prof)

    assert answer == correct_subject_list


def test_functions() -> None:
    test_add_student()
    test_add_subject()
    test_delete_student()
    test_delete_subject()
    test_modify_student()
    test_modify_subject()
    test_search_student_by_id()
    test_search_subject_by_id()
    test_search_student_by_name()
    test_search_subject_by_name()
    test_search_subject_by_prof()
    print("All tests passed!")
