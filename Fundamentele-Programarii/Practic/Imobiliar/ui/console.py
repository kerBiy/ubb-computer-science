from business.service import Service, ServiceError


class UiError(Exception):
    pass


class Console:
    def __init__(self, service: Service) -> None:
        self.__service = service

        self.__options = {
            "add": self.__ui_add_real_estate,
            "average": self.__ui_average_price,
            "transaction": self.__ui_make_transaction,
            "exit": self.__exit_app,
        }

    def __ui_add_real_estate(self, params: list[str]) -> None:
        """
        The Ui for the adding functionality.
        Input: A list of parameters
        Error: It catches value error from the params if they are not int of float
        """
        if len(params) != 4:
            raise UiError("Invalid params.")

        try:
            id = int(params[0])
            address = params[1].strip()
            desired_price = float(params[2])
            offer_type = params[3].strip()

            self.__service.add_real_estate(id, address, desired_price, offer_type)
            print("The real estate was added to the site")
        except ValueError:
            print("Value Error: Invalid numerical values.")

    def __ui_average_price(self, params: list[str]) -> None:
        """
        The Ui for the printing the average price of the type specified.
        Input: A list of parameters where is the type of offer
        Return: None, but prints the average price
        Error: It raises UiError if the param is not "chirie" or "vanzare"
        """
        if len(params) != 1:
            raise UiError("Invalid params.")

        offer_type = params[0].strip()

        if offer_type not in ["chirie", "vanzare"]:
            raise UiError("Invalid offer type.")

        average_price = self.__service.average_price(offer_type)
        print(f"The average price is: {average_price}$")

    def __ui_make_transaction(self, params: list[str]) -> None:
        """
        The Ui for making a transaction.
        Input: A list of parameters where is the id of the real estate and the price
        Return: None, but prints the address and the commission
        Error: It catches Service Error if there isn't a real estate with that id
        """
        if len(params) != 2:
            raise UiError("Invalid params.")

        try:
            id = int(params[0])
            price = float(params[1])

            address, commission = self.__service.make_transaction(id, price)
            print(f"The item is at {address} and the commission is {commission}$")

        except ValueError:
            print("Value Error: Invalid numerical value.")
        except ServiceError as se:
            print("Service Error:", se)

    def __exit_app(self, params: list[str]) -> None:
        if params != [""]:
            raise UiError("Invalid params.")

        print("Exiting the program...")
        exit(0)

    def __get_command(self, command: str) -> tuple:
        """
        Gets the command from the user.
        Input: the entire string from the keyboard
        Output: a tuple -> (first command, the params)
        """
        command = command.split()
        first_cmd = command[0]

        params = " ".join(command[1:])
        params = params.split(",")

        return first_cmd, params

    def run(self) -> None:
        """
        The main loop of the application
        """
        while True:
            command = input("\n>>> ")

            if command == "":
                continue

            first_cmd, params = self.__get_command(command)

            try:
                assert first_cmd in self.__options, "Invalid first command."
                self.__options[first_cmd](params)
            except Exception as ex:
                print("Error:", ex)
