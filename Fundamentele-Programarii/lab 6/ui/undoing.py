from functions import undo_command
from utils import print_expenses


def undo(expenses: list[dict], history: list[list[dict]]) -> None:
    print("Undoing last operation...")
    undo_command(expenses, history)
    print_expenses(expenses)
