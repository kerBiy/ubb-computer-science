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
            -hv value
                Searches all apartments with expenses higher than value
            -t type
                Searches all expenses of this type
            -bd date value
                Searches all the expenses before date and higher than val
        -print -* ...
            -ts type
                Prints out the sum of all expenses of this type
            -st type
                Prints out sorted apartments numbers by the exp of this type
            -as apartment
                Prints out the sum of all expenses at the apartment
        -filter -* ...
            -t type
                Filters all expenses that are this type
            -lv value
                Filters all expenses that have a lower value
        -undo
            Reverts the expenses to before the last operation
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


def list_to_str(nums: list) -> str:
    return ", ".join(map(str, nums))


def update_history(expenses: list[list], history: list[list[list]]) -> None:
    if expenses != history[-1]:
        history.append(expenses[:])
