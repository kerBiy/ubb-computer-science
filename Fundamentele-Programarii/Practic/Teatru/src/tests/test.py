from domain.entity import test_entity
from domain.validator import test_validator


class Test:
    @staticmethod
    def run():
        test_entity()
        test_validator()
