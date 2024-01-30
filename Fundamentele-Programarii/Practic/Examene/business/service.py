from datetime import datetime
from domain.entity import Examen
from domain.validator import Validator
from infrastructure.repository import Repository


class ServiceError(Exception):
    pass


class Service:
    def __init__(self, repository: Repository, validator: Validator) -> None:
        self.__repository = repository
        self.__validator = validator
        self.selected_date = None

    def get_today_exams(self) -> list[Examen]:
        today_date = datetime.now().date()

        today_exams = [
            exam for exam in self.__repository.items if exam.date == today_date
        ]

        return sorted(today_exams, key=lambda x: x.hour)

    def get_next_exams(self) -> list[Examen]:
        next_exams = [
            exam
            for exam in self.__repository.items
            if 0 <= (exam.date - self.selected_date).days <= 2
        ]

        return sorted(next_exams, key=lambda x: (x.date, x.hour))

    def add_examen(self, date: str, hour: str, subject: str, regular: bool) -> None:
        self.__validator.validate_date_and_hour(date, hour)

        new_examen = Examen(date, hour, subject, regular)
        self.__repository.add(new_examen)

    def set_date(self, date: str) -> None:
        self.__validator.valid_date(date)

        self.selected_date = datetime.strptime(date, "%d/%m").date().replace(year=2024)

    def export_exams(self, file_name: str, word: str) -> None:
        file_name = "data/" + file_name + ".txt"
        with open(file_name, "w") as file:
            exams = [item for item in self.__repository.items if word in item.subject]
            for exam in sorted(exams, key=lambda x: (x.date, x.hour)):
                file.write(f"{exam}\n")
