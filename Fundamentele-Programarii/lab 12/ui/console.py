from ui.ui import Ui


class Console:
    def __init__(self, student_manager, subject_manager, grade_manager) -> None:
        self.ui = Ui(
            student_manager,
            subject_manager,
            grade_manager,
        )

        self.options = {
            "print_stud": self.ui.print_students,
            "print_sub": self.ui.print_subjects,
            "print_grade": self.ui.print_grades,
            "add_stud": self.ui.add_student,
            "add_sub": self.ui.add_subject,
            "add_grade": self.ui.add_grade,
            "del_stud": self.ui.delete_student,
            "del_sub": self.ui.delete_subject,
            "del_grade": self.ui.delete_grade,
            "mod_stud": self.ui.modify_student,
            "mod_sub": self.ui.modify_subject,
            "mod_grade": self.ui.modify_grade,
            "search_stud_id": self.ui.search_student_id,
            "search_sub_id": self.ui.search_subject_id,
            "search_grade_id": self.ui.search_grade_id,
            "stats": self.ui.stats,
            "stats_ordered": self.ui.stats_ordered,
            "top20": self.ui.top20,
            "failing": self.ui.failing,
            "load": self.ui.load,
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
                assert first_command in self.options, "Invalid first command."
                self.options[first_command](cmd_arguments)
            except ValueError as ve:
                print(ve)
            except Exception as e:
                print(e)
