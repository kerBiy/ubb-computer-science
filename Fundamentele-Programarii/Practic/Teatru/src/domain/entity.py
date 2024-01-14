class TheatricalPiece:
    def __init__(self, name: str, director: str, genera: str, screen_time: int) -> None:
        self.__name = name
        self.__director = director
        self.__genera = genera
        self.__screen_time = screen_time

    def __str__(self) -> str:
        return f"{self.name}, {self.director}, {self.genera}, {self.screen_time}"

    @property
    def name(self) -> str:
        return self.__name

    @property
    def director(self) -> str:
        return self.__director

    @property
    def genera(self) -> str:
        return self.__genera

    @property
    def screen_time(self) -> int:
        return self.__screen_time


def test_entity() -> None:
    new_entity = TheatricalPiece("Hannibal", "Shakespeare", "Drama", 100)
    assert new_entity.name == "Hannibal"
    assert new_entity.director == "Shakespeare"
    assert new_entity.genera == "Drama"
    assert new_entity.screen_time == 100
