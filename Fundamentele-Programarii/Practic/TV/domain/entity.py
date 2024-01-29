class TvShow:
    def __init__(
        self, name: str, type: str, screen_time: int, description: str
    ) -> None:
        self.__name = name
        self.__type = type
        self.__screen_time = screen_time
        self.__description = description

    def __str__(self) -> str:
        return f"{self.name}, {self.type}, {self.screen_time}, {self.description}"

    @property
    def name(self) -> str:
        return self.__name

    @property
    def type(self) -> str:
        return self.__type

    @property
    def screen_time(self) -> int:
        return self.__screen_time

    @property
    def description(self) -> str:
        return self.__description


class TvShowDTO:
    def __init__(self) -> None:
        pass
