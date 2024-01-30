from domain.validator import ValidationError, Validator
from domain.entity import Examen


class Test:
    def __init__(self) -> None:
        pass

    def __domain_tests(self) -> None:
        print("Domain tests starting...")

        self.__date = "20/12"
        self.__hour = "16:30"
        self.__subject = "FP"
        self.__regular = True

        self.__examen = Examen(self.__date, self.__hour, self.__subject, self.__regular)
        # assert self.__examen.date == self.__date
        # assert self.__examen.hour == self.__hour
        assert self.__examen.subject == self.__subject
        assert self.__examen.regular == self.__regular

        print("Domain tests finished successfully")

    # def __validator_tests(self) -> None:
    #     print("Validator tests starting...")

    #     self.__validator = Validator()
    #     self.__validator.validate_examen(self.__examen)

    #     self.__bad_date = "13/60"
    #     self.__bad_hour = "34/234/42"
    #     self.__bad_examen = Examen(
    #         self.__bad_date, self.__bad_hour, self.__subject, self.__regular
    #     )

    #     try:
    #         self.__validator.validate_examen(self.__bad_examen)
    #         assert False
    #     except ValidationError as ve:
    #         assert str(ve) == "The date is not valid.\nThe hour is not valid."

    #     print("Validator tests finished successfully")

    def run_all(self) -> None:
        print("Tests starting...")
        self.__domain_tests()
        # self.__validator_tests()
        print("Tests run successfully")
