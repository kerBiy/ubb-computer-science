from infrastructure.functions import undo_command, can_undo


def undo(expenses: list[list], history: list[list[list]]) -> None:
    if can_undo(history):
        print("Undoing last operation...")
        undo_command(expenses, history)
    else:
        print("You cannot undo any further.")
