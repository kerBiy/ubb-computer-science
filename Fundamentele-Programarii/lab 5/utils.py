from os import system


def clear_screen() -> None:
    system("clear")


def get_command(prompt: str) -> list[str]:
    user_input = input(prompt)
    return user_input.strip().split()
