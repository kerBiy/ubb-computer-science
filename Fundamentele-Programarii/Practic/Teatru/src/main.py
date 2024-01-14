from infrastructure.repository import Repository
from business.service import Service
from console.ui import Ui
from tests.test import Test


class App:
    @staticmethod
    def main() -> None:
        repository = Repository("../data/database.txt")
        service = Service(repository)
        console = Ui(service)

        console.run()


if __name__ == "__main__":
    Test.run()
    App.main()
