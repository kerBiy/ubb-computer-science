import csv
from os import system

# Something random

# /----- Utilities -----/


def clear_screen() -> None:
    system("clear")


def get_input(expenses: list[dict], options: dict) -> None:
    print("Enter b to go back")
    user_input = input("\nEnter your option again: ")

    if user_input == "b":
        clear_screen()
        return

    user_input = int(user_input)
    clear_screen()
    options[user_input](expenses)


def read_from_csv(expenses: list[dict]) -> None:
    expenses = [*csv.DictReader(open("dataBase.csv"))]

    for i in range(len(expenses)):
        expenses[i]["apartment"] = int(expenses[i]["apartment"])
        expenses[i]["val"] = float(expenses[i]["val"])


def printExpenses(expenses: list[dict]) -> None:
    print("EXPENSES LIST:")
    for index, expense in enumerate(expenses):
        print(
            f"{index + 1}. Apartment: {expense['apartment']}, Value: {expense['val']}, Type: {expense['type']}, Date: {expense['date']}"
        )


# /----- Adding -----/


def addMenu(expenses: list[dict]) -> None:
    clear_screen()
    print("Enter 1 for adding an expenses")
    print("Enter 2 for modifying an expense")

    options = {1: add_expense, 2: modify_expense}
    get_input(expenses, options)


def add_expense(expenses: list[dict]) -> None:
    print("Adding an expense:\n")
    apartment = int(input("Enter the apartment number: "))
    value = float(input("Enter the expense value: "))
    type = input("Enter the expense type: ")
    date = input("Enter the expense date(yyyy/mm/dd): ")

    addExpense(expenses, apartment, value, type, date)


def modify_expense(expenses: list[dict]) -> None:
    printExpenses(expenses)

    id = int(input("\nPlease enter the id of the expense you want to modify: "))

    while id > len(expenses) or id <= 0:
        id = int(input("Please enter a valid id: "))

    apartment = int(input("\nEnter the expense apartment: "))
    value = float(input("Enter the expense value: "))
    type = input("Enter the expense type: ")
    date = input("Enter the expense date(yyyy/mm/dd): ")

    modifyExpenseAtApartment(expenses, id, apartment, value, type, date)


def addExpense(
    expenses: list[dict], apartment: int, val: float, type: str, date: str
) -> None:
    expenses.append({"apartment": apartment, "val": val, "type": type, "date": date})


def modifyExpenseAtApartment(
    expenses: list[dict], id: int, apartment: int, val: float, type: str, date: str
) -> None:
    id -= 1
    expenses[id]["apartment"] = apartment
    expenses[id]["val"] = val
    expenses[id]["type"] = type
    expenses[id]["date"] = date


def testAddExpense(expenses: list[dict]) -> None:
    new_expenses = expenses.copy()
    correct_expenses = expenses.copy()
    correct_expenses.append(
        {"apartment": 211, "val": 230.59, "type": "gas", "date": "2019/02/08"}
    )

    addExpense(new_expenses, 211, 230.59, "gas", "2019/02/08")

    assert new_expenses == correct_expenses
    print("JMK")


def testModifyExpense(expenses: list[dict]) -> None:
    pass


# /----- Deleting -----/


def deleteMenu(expenses: list[dict]) -> None:
    clear_screen()
    print("Enter 1 for deleting all the expenses of one apartment")
    print("Enter 2 for deleting all the consecutive apartments expenses")
    print("Enter 3 for deleting all the expenses of one type")

    options = {
        1: delete_expenses_apartment,
        2: delete_consecutive,
        3: delete_expenses_type,
    }

    get_input(expenses, options)


def delete_expenses_apartment(expenses: list[dict]) -> None:
    apartment = int(
        input("Enter the apartment number you want to delete all the expenses from: ")
    )
    deleteAllExpensesFrom(expenses, apartment)


def delete_consecutive(expenses: list[dict]) -> None:
    first_apartment = int(input("Enter the first apartment number: "))
    second_apartment = int(input("Enter the second apartment number: "))

    deleteConsecutiveExpensesFrom(expenses, first_apartment, second_apartment)


def delete_expenses_type(expenses: list[dict]) -> None:
    type = input("Enter the expense type you want to delete: ")
    deleteExpensesOfType(expenses, type)


def deleteAllExpensesFrom(expenses: list[dict], apartment: int) -> None:
    expenses[:] = [expense for expense in expenses if expense["apartment"] != apartment]


def deleteConsecutiveExpensesFrom(
    expenses: list[dict], apartment_start: int, apartment_end: int
) -> None:
    expenses[:] = [
        expense
        for expense in expenses
        if not apartment_start <= expense["apartment"] <= apartment_end
    ]


def deleteExpensesOfType(expenses: list[dict], type: str) -> None:
    expenses[:] = [expense for expense in expenses if expense["type"] != type]


def testDeleteExpenseApartment(expenses: list[dict]) -> None:
    pass


def testDeleteConsecutive(expenses: list[dict]) -> None:
    pass


def testDeleteExpenseType(expenses: list[dict]) -> None:
    pass


# /----- Main -----/


def mainMenu() -> None:
    print("\n\nOPTION MENU:")
    print("Enter 0 for showing the expenses list")
    print("Enter 1 for add menu")
    print("Enter 2 for delete menu")
    print("Enter q for Exiting the program")


def testFunction() -> None:
    expenses = []
    read_from_csv(expenses)

    testAddExpense(expenses)
    testModifyExpense(expenses)
    testDeleteExpenseApartment(expenses)
    testDeleteConsecutive(expenses)
    testDeleteExpenseType(expenses)


def main():
    expenses = []
    options = {
        0: printExpenses,
        1: addMenu,
        2: deleteMenu,
    }

    while True:
        mainMenu()
        user_input = input("\nEnter an option: ")
        clear_screen()

        if user_input == "q":
            print("Exiting the program...")
            break

        try:
            user_input = int(user_input)
            options[user_input](expenses)
        except ValueError:
            print("Invalid input.")
        except KeyError:
            print("This option is not yet implemented.")


if __name__ == "__main__":
    testFunction()
    main()
