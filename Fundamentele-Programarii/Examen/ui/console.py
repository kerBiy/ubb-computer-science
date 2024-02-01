from business.service import Service, ServiceError


class UiError(Exception):
    pass


class Console:
    def __init__(self, service: Service) -> None:
        self.__service = service

        self.__options = {
            "add": self.__add_item,
            "delete": self.__delete_by_price,
            "filter": self.__change_filter,
            "undo": self.__undo,
            "exit": self.__exit_app,
        }

    def __add_item(self, params: list[str]) -> None:
        if len(params) != 5:
            raise UiError("Invalid params.")

        try:
            id = int(params[0])
            name = params[1].strip()
            price = float(params[2])
            model = params[3]
            date = params[4]

            self.__service.add_tractor(id, name, price, model, date)
            print("The tractor was added in the database")
        except ValueError:
            print("Value Error: Invalid numerical args.")
        except ServiceError as se:
            print("Service Error:", se)

    def __delete_by_price(self, params: list[str]) -> None:
        if len(params) != 1:
            raise UiError("Invalid params.")

        digit = int(params[0])
        number = self.__service.delete_by_price(digit)
        print(f"{number} items were deleted")

    def __print_filtered_list(self) -> None:
        if self.__service.filter == ("", -1):
            return

        items = self.__service.filtered_list()

        print(f"\nWith the filter {self.__service.filter}:")
        for item in items:
            print(item)

    def __change_filter(self, params: list[str]) -> None:
        if len(params) != 2:
            raise UiError("Invalid params.")

        try:
            filter = (params[0], float(params[1]))
            self.__service.filter = filter
            print("The filter has changed.")
        except ValueError:
            print("Value Error: Invalid numerical args.")

    def __undo(self, params: list[str]) -> None:
        if len(params) != 0:
            raise UiError("Invalid params.")

        try:
            self.__service.undo_command()
            print("Undoing the lats operation...")
        except ServiceError as se:
            print(se)

    def __exit_app(self, params: list[str]) -> None:
        if len(params) != 0:
            raise UiError("Invalid params.")

        print("Exiting the program...")
        exit(0)

    def run(self) -> None:
        while True:
            self.__print_filtered_list()

            command = input("\n>>> ")

            if command == "":
                continue

            command = command.strip().split()
            first_cmd, params = command[0], command[1:]

            try:
                assert first_cmd in self.__options, "The option is not yet implemented"

                self.__options[first_cmd](params)
                self.__service.update_history()
            except UiError as ue:
                print("Ui Error:", ue)
            except Exception as e:
                print("Error:", e)
