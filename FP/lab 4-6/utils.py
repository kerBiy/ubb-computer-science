from os import system


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
