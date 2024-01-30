from datetime import datetime


class Examen:
    def __init__(self, date: str, hour: str, subject: str, regular: bool) -> None:
        self.__date = datetime.strptime(date, "%d/%m").date().replace(year=2024)
        self.__hour = datetime.strptime(hour, "%H:%M").time()
        self.__subject = subject
        self.__regular = regular

    def __str__(self) -> str:
        return f"{self.date.strftime("%d/%m")},{self.hour.strftime("%H:%M")},{self.subject},{self.regular}"

    def __eq__(self, __value: object) -> bool:
        return (
            self.date == __value.date
            and self.hour == __value.hour
            and self.subject == __value.subject
            and self.regular == __value.regular
        )

    @property
    def date(self) -> datetime:
        return self.__date

    @property
    def hour(self) -> datetime:
        return self.__hour

    @property
    def subject(self) -> str:
        return self.__subject

    @property
    def regular(self) -> bool:
        return self.__regular
