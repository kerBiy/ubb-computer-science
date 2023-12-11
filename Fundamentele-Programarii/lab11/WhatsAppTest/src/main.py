from console.ui import Ui
from business.manager import Manager
from infrastructure.repository import Repository


def main() -> None:
    file_name = "dataBase/stock.txt"

    furniture_repo = Repository(file_name)
    furniture_manager = Manager(furniture_repo)

    app = Ui(furniture_manager)
    app.run()


if __name__ == "__main__":
    main()
