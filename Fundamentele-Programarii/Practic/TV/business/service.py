from random import shuffle

from infrastructure.repository import Repository, RepoError
from domain.entity import TvShow


class ValidError(Exception):
    pass


class Service:
    def __init__(self, repository: Repository) -> None:
        self.__repository = repository

    def delete(self, name: str, type: str) -> None:
        try:
            self.__repository.delete(name, type)
        except RepoError as re:
            print("Repository Error:", re)

    def modify(
        self, name: str, type: str, new_screen_time: int, new_description: str
    ) -> None:
        try:
            new_show = TvShow(name, type, new_screen_time, new_description)
            self.__repository.modify(new_show)
        except RepoError as re:
            print("Repository Error:", re)

    def random(self, start: int, end: int) -> list:
        if not 0 <= start < end <= 24:
            raise ValidError("The hours given are not valid.")

        output_schedule = []

        def recursive_random(current: int, items: list, output: list) -> None:
            item_list = items.copy()
            found = False

            while item_list:
                shuffle(item_list)
                show = item_list.pop()

                if current + show.screen_time <= end:
                    found = True
                    new_show = [
                        current,
                        show.name,
                        show.type,
                        show.description,
                    ]

                    if len([item for item in output if item[1] == new_show[1]]) == 0:
                        output.append(new_show)
                    else:
                        new_show[3] = "****"
                        output.append(new_show)

                    current += show.screen_time

                if current == end:
                    return

            if found:
                return recursive_random(current, items, output)
            return

        recursive_random(start, self.__repository.items, output_schedule)

        return output_schedule
