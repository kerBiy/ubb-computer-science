from os import system
from datetime import strptime


def clear_screen() -> None:
    system("clear")


def valid_date(date: str) -> bool:
    format = "%Y/%m/%d"
    return strptime(date, format)


def input_number(prompt: str, function):
    while True:
        try:
            user_input = input(prompt)
            user_input = function(user_input)
            assert user_input >= 0
            return user_input
        except Exception:
            print("\nPlease enter a valid number.")


def input_date(prompt: str) -> str:
    while True:
        try:
            user_input = input(prompt)
            assert valid_date(user_input)
            return user_input
        except Exception:
            print("\nPlease enter a valid date.")


def input_id(prompt: str, expenses: list[dict]) -> int:
    while True:
        try:
            user_input = input(prompt)
            user_input = int(user_input)
            assert 1 <= user_input <= len(expenses)
        except Exception:
            print("\nPlease enter a valid id: ")


def get_input_for_submenu(expenses: list[dict], options: dict) -> None:
    print("Enter b to go back")
    user_input = input("\nEnter your option again: ")
    clear_screen()

    if user_input == "b":
        return

    user_input = int(user_input)
    options[user_input](expenses)


def print_expenses(expenses: list[dict]) -> None:
    print("EXPENSES LIST:")
    for index, expense in enumerate(expenses):
        print(
            f"{index + 1}. Apartment: {expense['apartment']}, Value: {expense['val']}, Type: {expense['type']}, Date: {expense['date']}"
        )
