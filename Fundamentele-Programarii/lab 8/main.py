from ui.console import Console
from validate.test import test_functions


if __name__ == "__main__":
    test_functions()

    console = Console()
    console.run_application()