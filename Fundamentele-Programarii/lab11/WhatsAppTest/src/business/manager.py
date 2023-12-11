from infrastructure.repository import Repository


class Manager:
    def __init__(self, furniture_repo: Repository) -> None:
        self.repository = furniture_repo

    def search(self, object_type: str) -> list:
        return self.repository.search(object_type)

    def buy(self, code: int, count: int) -> None:
        return self.repository.update(code, count)
