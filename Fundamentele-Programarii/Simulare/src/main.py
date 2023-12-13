from console.ui import Ui
from infrastructure.repository import Repository
from business.manager import Manager
from tests.test import Test


def main() -> None:
    file_name = "database/locations.txt"
    test_file = "database/test.txt"

    tests = Test(test_file)
    tests.run_all_tests()

    repository = Repository(file_name)
    manager = Manager(repository)
    app = Ui(manager)

    app.run()


if __name__ == "__main__":
    main()
