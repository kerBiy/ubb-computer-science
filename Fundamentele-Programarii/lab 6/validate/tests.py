from infrastructure.functions import *


# /----- Adding -----/


def test_add_expense() -> None:
    new_expense = []
    correct_expense = [[112, 350.99, "gas", "2020/05/22"]]
    expense = [112, 350.99, "gas", "2020/05/22"]

    add_expense(new_expense, expense)

    assert correct_expense == new_expense


def test_modify_expense() -> None:
    new_expense = [[113, 50.98, "gas", "2020/05/20"]]
    correct_expense = [[112, 350.99, "gas", "2020/05/22"]]
    expense = [112, 350.99, "gas", "2020/05/22"]

    id_expense = 1
    modify_expense(new_expense, id_expense, expense)

    assert correct_expense == new_expense


# /----- Deleting -----/


def test_delete_all_expenses_from_apartment() -> None:
    new_expenses = [
        [112, 950.99, "trash", "2021/10/22"],
        [102, 99.99, "light", "2022/05/22"],
        [112, 2020.50, "gas", "2020/05/27"],
        [113, 350.99, "gas", "2020/05/22"],
    ]
    correct_expenses = [
        [102, 99.99, "light", "2022/05/22"],
        [113, 350.99, "gas", "2020/05/22"],
    ]

    delete_all_expenses_from_apartment(new_expenses, 112)

    assert correct_expenses == new_expenses


def test_delete_all_consecutive_expenses() -> None:
    new_expenses = [
        [112, 950.99, "trash", "2021/10/22"],
        [102, 99.99, "light", "2022/05/22"],
        [112, 2020.50, "gas", "2020/05/27"],
        [113, 350.99, "gas", "2020/05/22"],
    ]
    correct_expenses = [[102, 99.99, "light", "2022/05/22"]]

    delete_all_consecutive_expenses(new_expenses, 105, 115)

    assert correct_expenses == new_expenses


def test_delete_all_expenses_of_same_type() -> None:
    new_expenses = [
        [112, 950.99, "trash", "2021/10/22"],
        [102, 99.99, "light", "2022/05/22"],
        [112, 2020.50, "gas", "2020/05/27"],
        [113, 350.99, "gas", "2020/05/22"],
    ]
    correct_expenses = [
        [112, 950.99, "trash", "2021/10/22"],
        [102, 99.99, "light", "2022/05/22"],
    ]

    delete_all_expenses_of_same_type(new_expenses, "gas")

    assert correct_expenses == new_expenses


# /----- Searching -----/


def test_search_all_apartments_with_expenses_higher_than() -> None:
    new_expenses = [
        [113, 250.99, "trash", "2021/10/22"],
        [102, 99.99, "light", "2022/05/22"],
        [113, 120.50, "gas", "2020/05/27"],
        [112, 350.99, "gas", "2020/05/22"],
    ]
    correct_result = [112, 113]

    search_result = search_all_apartments_with_expenses_higher_than(new_expenses, 300)

    assert correct_result == search_result


def test_search_all_expenses_of_type() -> None:
    new_expenses = [
        [112, 950.99, "trash", "2021/10/22"],
        [102, 99.99, "light", "2022/05/22"],
        [112, 2020.50, "gas", "2020/05/27"],
        [113, 350.99, "gas", "2020/05/22"],
    ]
    correct_result = {
        2: [112, 2020.50, "gas", "2020/05/27"],
        3: [113, 350.99, "gas", "2020/05/22"],
    }

    search_result = search_all_expenses_of_type(new_expenses, "gas")

    assert correct_result == search_result


def test_search_all_expenses_before_date_bigger_than_value() -> None:
    new_expenses = [
        [112, 950.99, "trash", "2021/10/22"],
        [102, 99.99, "light", "2022/05/22"],
        [112, 20.50, "gas", "2020/05/27"],
        [113, 350.99, "gas", "2020/05/22"],
    ]
    correct_result = {
        0: [112, 950.99, "trash", "2021/10/22"],
        3: [113, 350.99, "gas", "2020/05/22"],
    }

    search_result = search_all_expenses_before_date_bigger_than_value(
        new_expenses, "2021/11/01", 300
    )

    assert correct_result == search_result


# /----- Printing -----/


def test_print_total_sum_expenses_of_type() -> None:
    new_expenses = [
        [112, 950.99, "trash", "2021/10/22"],
        [102, 99.99, "light", "2022/05/22"],
        [112, 2020.50, "gas", "2020/05/27"],
        [113, 350.99, "gas", "2020/05/22"],
    ]
    correct_result = 2371.49

    my_result = print_total_sum_expenses_of_type(new_expenses, "gas")

    assert my_result == correct_result


def test_print_sorted_apartments_by_type() -> None:
    new_expenses = [
        [113, 999.99, "trash", "2021/10/22"],
        [102, 99.99, "light", "2022/05/22"],
        [112, 920.50, "gas", "2020/05/27"],
        [113, 350.99, "gas", "2020/05/22"],
    ]
    correct_result = [112, 113]

    my_result = print_sorted_apartments_by_type(new_expenses, "gas")

    assert my_result == correct_result


def test_print_total_sum_expenses_of_the_apartment() -> None:
    new_expenses = [
        [112, 950.99, "trash", "2021/10/22"],
        [102, 99.99, "light", "2022/05/22"],
        [112, 2020.50, "gas", "2020/05/27"],
        [113, 350.99, "gas", "2020/05/22"],
    ]
    correct_result = 2020.50 + 950.99

    my_result = print_total_sum_expenses_of_the_apartment(new_expenses, 112)

    assert my_result == correct_result


# /----- Filtering -----/


def test_eliminate_all_expenses_of_type() -> None:
    new_expenses = [
        [112, 950.99, "trash", "2021/10/22"],
        [102, 99.99, "light", "2022/05/22"],
        [112, 2020.50, "gas", "2020/05/27"],
        [113, 350.99, "gas", "2020/05/22"],
    ]
    correct_expenses = {
        0: [112, 950.99, "trash", "2021/10/22"],
        1: [102, 99.99, "light", "2022/05/22"],
    }

    new_expense = eliminate_all_expenses_of_type(new_expenses, "gas")

    assert correct_expenses == new_expense


def test_eliminate_all_expenses_lower_than() -> None:
    new_expenses = [
        [112, 950.99, "trash", "2021/10/22"],
        [102, 99.99, "light", "2022/05/22"],
        [112, 2020.50, "gas", "2020/05/27"],
        [113, 350.99, "gas", "2020/05/22"],
    ]
    correct_expenses = {
        0: [112, 950.99, "trash", "2021/10/22"],
        2: [112, 2020.50, "gas", "2020/05/27"],
    }

    new_expense = eliminate_all_expenses_lower_than(new_expenses, 800)

    assert correct_expenses == new_expense


def test_functions() -> None:
    test_add_expense()
    test_modify_expense()
    test_delete_all_expenses_from_apartment()
    test_delete_all_consecutive_expenses()
    test_delete_all_expenses_of_same_type()
    test_search_all_apartments_with_expenses_higher_than()
    test_search_all_expenses_of_type()
    test_search_all_expenses_before_date_bigger_than_value()
    test_print_total_sum_expenses_of_type()
    test_print_sorted_apartments_by_type()
    test_print_sorted_apartments_by_type()
    test_eliminate_all_expenses_of_type()
    test_eliminate_all_expenses_lower_than()
    print("All tests passed!")
