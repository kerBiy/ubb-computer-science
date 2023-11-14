from business.manager import ManagerStudent, ManagerSubject

from ui.print import PrintUI
from ui.add import AddUI
from ui.delete import DeleteUI
from ui.modify import ModifyUI


class Console:
    def __init__(self) -> None:
        self.student_manager = ManagerStudent()
        self.subject_manager = ManagerSubject()

        self.print_ui = PrintUI(self.student_manager, self.subject_manager)
        self.add_ui = AddUI(self.student_manager, self.subject_manager)
        self.delete_ui = DeleteUI(self.student_manager, self.subject_manager)
        self.modify_ui = ModifyUI(self.student_manager, self.subject_manager)

        self.options = {
            "print_stud": self.print_ui.print_students,
            "print_sub": self.print_ui.print_subjects,
            "add_stud": self.add_ui.add_student,
            "add_sub": self.add_ui.add_subject,
            "del_stud": self.delete_ui.delete_student,
            "del_sub": self.delete_ui.delete_subject,
            "mod_stud": self.modify_ui.modify_student,
            "mod_sub": self.modify_ui.modify_subject,
            # "search_stud_id": ui_search_id,
            # "search_sub_id": ui_search_subject_by_id,
            # "search_stud_name": ui_search_name,
            # "search_sub_name": ui_search_subject_by_name,
            # "search_prof": ui_search_subject_by_prof,
        }

    def get_first_command(self, command: str) -> str:
        command = command.split()
        first_command = command[0].strip() if command else ""
        cmd_arguments = " ".join(command[1:])
        cmd_arguments = cmd_arguments.split(",")

        return first_command, cmd_arguments

    def run_application(self) -> None:
        while True:
            command = input("\n>>> ")
            first_command, cmd_arguments = self.get_first_command(command)

            if first_command == "exit":
                print("Exiting the program...")
                return

            try:
                assert first_command in self.options.keys(), "Invalid first command."
                self.options[first_command](cmd_arguments)
            except ValueError as ve:
                print(ve)
            except Exception as e:
                print(e)
