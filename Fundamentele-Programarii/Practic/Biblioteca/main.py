from ui.console import Console
from business.service import Service
from infrastructure.repository import Repository


class Application:
    def __init__(self) -> None:
        self.repository = Repository("data/database.txt")
        self.service = Service(self.repository)
        self.console = Console(self.service)

    def main(self) -> None:
        self.console.run()


if __name__ == "__main__":
    app = Application()
    app.main()
