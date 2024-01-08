from console.ui import Ui
from business.manager import Manager
from infrastructure.repository import Repository
from domain.validate import Validator
from tests.test import Test


def main() -> None:
    file_name = "dataBase/stock.txt"
    test_file_name = "dateBase/stockTest.txt"

    tester = Test(test_file_name)
    tester.test_all()

    furniture_repo = Repository(file_name)
    furniture_validator = Validator()

    furniture_manager = Manager(furniture_repo, furniture_validator)

    app = Ui(furniture_manager)
    app.run()


if __name__ == "__main__":
    main()
