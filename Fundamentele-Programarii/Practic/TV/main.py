from infrastructure.repository import Repository
from business.service import Service
from ui.console import Console


class Application:
    def __init__(self) -> None:
        self.repository = Repository("data/database.txt")
        self.service = Service(self.repository)
        self.console = Console(self.service)

    def main(self) -> None:
        self.console.run()


if __name__ == "__main__":
    # Tests.run_all()

    my_app = Application()
    my_app.main()
