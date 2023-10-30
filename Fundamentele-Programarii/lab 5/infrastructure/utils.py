from infrastructure.domain import get_apartment, get_value, get_type, get_date


def get_command(prompt: str) -> list[str]:
    user_input = input(prompt)
    return user_input.strip().split()


def help_menu() -> str:
    return """ 
        COMMANDS LIST:
        --------------
        -list 
            Prints the expenses list
        -add apartment value type date
            Adds the expense in expenses
        -modify id apartment value type date
            Modify the expense at the id given
        -delete -* ...
            -a apartment
                Deletes all expenses from this apartment
            -c first_apartment second_apartment
                Deletes all consecutive expenses
            -t type
                Deletes all expenses of this type
        -search -* ...
            -t type
                Searches all expenses of this type
        
            """


def print_expenses(expenses) -> None:
    print("EXPENSES LIST:")
    for index, expense in enumerate(expenses):
        print(
            f"{index + 1}. Apartment: {get_apartment(expense)}, Value: {get_value(expense)}, Type: {get_type(expense)}, Date: {get_date(expense)}"
        )


def print_dict(expenses: dict) -> None:
    print("EXPENSES LIST:")
    for key, expense in expenses.items():
        print(
            f"{key + 1}. Apartment: {get_apartment(expense)}, Value: {get_value(expense)}, Type: {get_type(expense)}, Date: {get_date(expense)}"
        )


def update_history(expenses: list[dict], history: list[list[dict]]) -> None:
    if expenses != history[-1]:
        history.append(expenses[:])
