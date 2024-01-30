from datetime import datetime
from domain.entity import Examen


class ValidationError(Exception):
    pass


class Validator:
    def __init__(self) -> None:
        pass

    def valid_date(self, date: str) -> bool:
        try:
            self.__date = datetime.strptime(date, "%d/%m")
            return True
        except ValueError:
            return False

    def valid_hour(self, hour: datetime) -> bool:
        try:
            self.__hour = datetime.strptime(hour, "%H:%M").time()
            return True
        except ValueError:
            return False

    def validate_date_and_hour(self, date: datetime, hour: datetime) -> None:
        error = ""

        if not self.valid_date(date):
            error += "The date is not valid.\n"
        if not self.valid_hour(hour):
            error += "The hour is not valid.\n"

        if error:
            raise ValidationError(error[:-1])
