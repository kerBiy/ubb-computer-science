from business.service import Service, ServiceError


class UiError(Exception):
    pass


class Console:
    def __init__(self, service: Service) -> None:
        self.__service = service

        self.__options = {
            "add": self.__add_examen,
            "set_date": self.__set_date,
            "export": self.__export_examens,
            "exit": self.__exit_app,
        }

    def __print_today_exams(self) -> None:
        today_exams = self.__service.get_today_exams()

        if not today_exams:
            print("\nThere are no exams today")
            return

        print("\nThe today exams are: ")
        for exam in today_exams:
            print(exam)

    def __exams_next_tree_days(self) -> None:
        next_exams = self.__service.get_next_exams()

        if not next_exams:
            print("\nThere are no exams in the next 3 days")
            return

        print("\nThe next exams are: ")
        for exam in next_exams:
            print(exam)

    def __add_examen(self, params: list[str]) -> None:
        if len(params) != 4:
            raise UiError("Invalid params.")

        data = params[0]
        hour = params[1]
        subject = params[2]
        regular = True if params[3] == "True" else False

        try:
            self.__service.add_examen(data, hour, subject, regular)
            print("The examen was added in the database")
        except ServiceError as se:
            print("Service Error:", se)

    def __set_date(self, params: list[str]) -> None:
        if len(params) != 1:
            raise UiError("Invalid params.")

        str_date = params[0]

        try:
            self.__service.set_date(str_date)
            print("The date was modified")
        except ServiceError as se:
            print("Service Error:", se)

    def __export_examens(self, params: list[str]) -> None:
        if len(params) != 2:
            raise UiError("Invalid params.")

        file_name = params[0]
        word = params[1]

        try:
            self.__service.export_exams(file_name, word)
            print("The exams were exported")
        except ServiceError as se:
            print("Service Error:", se)

    def __exit_app(self, params: list[str]) -> None:
        if len(params) != 0:
            raise UiError("Invalid params.")

        print("Exiting the program...")
        exit(0)

    def run(self) -> None:
        self.__print_today_exams()

        while True:
            self.__exams_next_tree_days() if self.__service.selected_date else None

            command = input("\n>>> ")

            if command == "":
                continue

            command = command.strip().split()
            first_cmd, params = command[0], command[1:]

            try:
                assert first_cmd in self.__options, "Invalid command."
                self.__options[first_cmd](params)
            except Exception as ex:
                print("Error:", ex)
