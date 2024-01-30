from infrastructure.repository import Repository
from business.service import Service
from ui.console import Console
from tests.test import Test


class Application:
    def __init__(self) -> None:
        self.test = Test()
        self.repository = Repository("data/database.txt")
        self.service = Service(self.repository)
        self.console = Console(self.service)

    def run_tests(self) -> None:
        """
        Runs all the tests from the test module
        """
        self.test.run_all()

    def main(self) -> None:
        """
        Runs the main loop from the console module
        """
        self.console.run()


if __name__ == "__main__":
    app = Application()
    app.run_tests()
    app.main()
