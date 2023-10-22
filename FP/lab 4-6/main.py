from os import system


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


def addExpense(
    expenses: list[dict], apartment: int, val: float, type: str, date: str
) -> None:
    expenses.append({"apartment": apartment, "val": val, "type": type, "date": date})


def modifyExpenseAtApartment(
    expenses: list[dict], apartment: int, val: float, type: str, date: str
) -> None:
    for expense in expenses:
        if expense["apartment"] == apartment:
            expense["val"] = val
            expense["type"] = type
            expense["date"] = date


def add_expense(expenses: list[dict]) -> None:
    print("Adding an expense:\n")
    apartment = int(input("Enter the apartment number: "))
    value = float(input("Enter the expense value: "))
    type = input("Enter the expense type: ")
    date = input("Enter the expense date(yyyy/mm/dd): ")

    addExpense(expenses, apartment, value, type, date)


def modify_expense(expenses: list[dict]) -> None:
    apartment = int(input("Enter the apartment number you want to modify: "))
    value = float(input("\nEnter the expense value: "))
    type = input("Enter the expense type: ")
    date = input("Enter the expense date(yyyy/mm/dd): ")

    modifyExpenseAtApartment(expenses, apartment, value, type, date)


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


# /----- Main -----/


def mainMenu() -> None:
    print("\n\nOPTION MENU:")
    print("Enter 0 for showing the expenses list")
    print("Enter 1 for add menu")
    print("Enter 2 for delete menu")
    print("Enter q for Exiting the program")


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
        system("clear")

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
    main()
