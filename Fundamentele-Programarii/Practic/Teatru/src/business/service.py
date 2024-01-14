from infrastructure.repository import Repository
from domain.entity import TheatricalPiece
from domain.validator import Validator


class Service:
    def __init__(self, repository: Repository) -> None:
        self.__repository = repository

    def add(self, name: str, director: str, genera: str, screen_time: int) -> None:
        new_piece = TheatricalPiece(name, director, genera, screen_time)
        Validator.validate_theatrical_piece(new_piece)

        self.__repository.add(new_piece)

    def modify(
        self, name: str, director: str, new_genera: str, new_screen_time: int
    ) -> None:
        new_piece = TheatricalPiece(name, director, new_genera, new_screen_time)
        Validator.validate_theatrical_piece(new_piece)

        self.__repository.modify(new_piece)

    def generate(self, number_of_pieces: int) -> list:
        pieces_list = self.__repository.generate(number_of_pieces)
        return pieces_list
