from recursive import RecursiveBack
from iterative import IterativeBack


class Console:
    def __init__(self) -> None:
        self.recursive = RecursiveBack()
        self.iterative = IterativeBack()

    def print_menu(self) -> None:
        print("\nOPTION MENU")
        print("Press 1 for entering the list")
        print("Press 2 for using recursive backtracking")
        print("Press 3 for using iterative backtracking")

    def get_option(self) -> int:
        try:
            option = input("Enter a number: ")
            option = int(option)
            return option
        except ValueError:
            print("Please enter a number.")

    def get_input_list(self) -> None:
        try:
            array_string = input("Please enter your list: ")
            array_list = array_string.split()

            array = [int(elem) for elem in array_list]
            return array
        except Exception:
            print("The array is invalid.")

    def recursive_method(self, nums: list[int]) -> None:
        self.recursive.back(nums)

    def iterative_method(self, nums: list[int]) -> None:
        self.iterative.back(nums)

    def run(self) -> None:
        nums = []

        while True:
            self.print_menu()
            option = self.get_option()

            if option == 0:
                print("Exiting the app...")
                return
            elif option == 1:
                nums = self.get_input_list()
            elif option == 2:
                self.recursive_method(nums)
            elif option == 3:
                self.iterative_method(nums)
            else:
                print("This option is not yet implemented.")


if __name__ == "__main__":
    application = Console()
    application.run()
