from functions import undo_command, can_undo
from utils import print_expenses


def undo(expenses: list[dict], history: list[list[dict]]) -> None:
    if can_undo(history):
        print("Undoing last operation...")
        undo_command(expenses, history)
        print_expenses(expenses)
    else:
        print("You cannot undo any further.")
