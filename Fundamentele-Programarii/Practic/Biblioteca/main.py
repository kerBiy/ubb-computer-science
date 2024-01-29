from ui.console import Console
from business.service import Service
from infrastructure.repository import Repository
from tests.test import Test


class Application:
    def __init__(self) -> None:
        self.repository = Repository("data/database.txt")
        self.service = Service(self.repository)
        self.console = Console(self.service)

    def main(self) -> None:
        self.console.run()


if __name__ == "__main__":
    test = Test()
    test.run_all()

    app = Application()
    app.main()
