from functions import *


# /----- Adding -----/


def test_add_expense() -> None:
    new_expense = []
    correct_expense = [
        {"apartment": 112, "val": 350.99, "type": "gas", "date": "2020/05/22"}
    ]

    add_expense(new_expense, 112, 350.99, "gas", "2020/05/22")

    assert correct_expense == new_expense


def test_modify_expense() -> None:
    new_expense = [
        {"apartment": 113, "val": 50.98, "type": "gas", "date": "2020/05/20"}
    ]
    correct_expense = [
        {"apartment": 112, "val": 350.99, "type": "gas", "date": "2020/05/22"}
    ]

    id_expense = 1
    modify_expense(new_expense, id_expense, 112, 350.99, "gas", "2020/05/22")

    assert correct_expense == new_expense


# /----- Deleting -----/


def test_delete_all_expenses_from_apartment() -> None:
    new_expenses = [
        {"apartment": 112, "val": 950.99, "type": "trash", "date": "2021/10/22"},
        {"apartment": 102, "val": 99.99, "type": "light", "date": "2022/05/22"},
        {"apartment": 112, "val": 2020.50, "type": "gas", "date": "2020/05/27"},
        {"apartment": 113, "val": 350.99, "type": "gas", "date": "2020/05/22"},
    ]
    correct_expenses = [
        {"apartment": 102, "val": 99.99, "type": "light", "date": "2022/05/22"},
        {"apartment": 113, "val": 350.99, "type": "gas", "date": "2020/05/22"},
    ]

    delete_all_expenses_from_apartment(new_expenses, 112)

    assert correct_expenses == new_expenses


def test_delete_consecutive_expenses() -> None:
    new_expenses = [
        {"apartment": 112, "val": 950.99, "type": "trash", "date": "2021/10/22"},
        {"apartment": 102, "val": 99.99, "type": "light", "date": "2022/05/22"},
        {"apartment": 112, "val": 2020.50, "type": "gas", "date": "2020/05/27"},
        {"apartment": 113, "val": 350.99, "type": "gas", "date": "2020/05/22"},
    ]
    correct_expenses = [
        {"apartment": 102, "val": 99.99, "type": "light", "date": "2022/05/22"}
    ]

    delete_consecutive_expenses(new_expenses, 105, 115)

    assert correct_expenses == new_expenses


def test_delete_all_expenses_of_the_same_type() -> None:
    new_expenses = [
        {"apartment": 112, "val": 950.99, "type": "trash", "date": "2021/10/22"},
        {"apartment": 102, "val": 99.99, "type": "light", "date": "2022/05/22"},
        {"apartment": 112, "val": 2020.50, "type": "gas", "date": "2020/05/27"},
        {"apartment": 113, "val": 350.99, "type": "gas", "date": "2020/05/22"},
    ]
    correct_expenses = [
        {"apartment": 112, "val": 950.99, "type": "trash", "date": "2021/10/22"},
        {"apartment": 102, "val": 99.99, "type": "light", "date": "2022/05/22"},
    ]

    delete_all_expenses_of_the_same_type(new_expenses, "gas")

    assert correct_expenses == new_expenses


# /----- Searching -----/


def test_search_all_expenses_of_type() -> None:
    new_expenses = [
        {"apartment": 112, "val": 950.99, "type": "trash", "date": "2021/10/22"},
        {"apartment": 102, "val": 99.99, "type": "light", "date": "2022/05/22"},
        {"apartment": 112, "val": 2020.50, "type": "gas", "date": "2020/05/27"},
        {"apartment": 113, "val": 350.99, "type": "gas", "date": "2020/05/22"},
    ]
    correct_result = [
        {"apartment": 112, "val": 2020.50, "type": "gas", "date": "2020/05/27"},
        {"apartment": 113, "val": 350.99, "type": "gas", "date": "2020/05/22"},
    ]

    search_result = search_all_expenses_of_type(new_expenses, "gas")

    assert correct_result == search_result


# /----- Printing -----/


def test_print_total_sum_expenses_of_type() -> None:
    new_expenses = [
        {"apartment": 112, "val": 950.99, "type": "trash", "date": "2021/10/22"},
        {"apartment": 102, "val": 99.99, "type": "light", "date": "2022/05/22"},
        {"apartment": 112, "val": 2020.50, "type": "gas", "date": "2020/05/27"},
        {"apartment": 113, "val": 350.99, "type": "gas", "date": "2020/05/22"},
    ]
    correct_result = 2371.49

    my_result = print_total_sum_expenses_of_type(new_expenses, "gas")

    assert my_result == correct_result


# /----- Filtering -----/


def test_eliminate_all_expenses_lower_than() -> None:
    new_expenses = [
        {"apartment": 112, "val": 950.99, "type": "trash", "date": "2021/10/22"},
        {"apartment": 102, "val": 99.99, "type": "light", "date": "2022/05/22"},
        {"apartment": 112, "val": 2020.50, "type": "gas", "date": "2020/05/27"},
        {"apartment": 113, "val": 350.99, "type": "gas", "date": "2020/05/22"},
    ]
    correct_expenses = [
        {"apartment": 112, "val": 950.99, "type": "trash", "date": "2021/10/22"},
        {"apartment": 112, "val": 2020.50, "type": "gas", "date": "2020/05/27"},
    ]

    eliminate_all_expenses_lower_than(new_expenses, 800)

    assert correct_expenses == new_expenses


def test_functions() -> None:
    test_add_expense()
    test_modify_expense()
    test_delete_all_expenses_from_apartment()
    test_delete_consecutive_expenses()
    test_delete_all_expenses_of_the_same_type()
    test_search_all_expenses_of_type()
    test_print_total_sum_expenses_of_type()
    test_eliminate_all_expenses_lower_than()
    print("All tests passed!")
