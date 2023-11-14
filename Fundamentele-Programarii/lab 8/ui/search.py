# class SearchUI:
#     def ui_search_id(
#         students: list, subjects: list[list], cmd: list[str]
#     ) -> None:
#         if len(cmd) != 1:
#             raise Exception("Invalid command arguments.")

#         student_id = int(cmd[0])

#         student_name = manager_search_id(students, student_id)
#         print(f"{student_id}. {student_name}")


#     def ui_search_subject_by_id(
#         students: list, subjects: list[list], cmd: list[str]
#     ) -> None:
#         if len(cmd) != 1:
#             raise Exception("Invalid command parameters.")

#         subject_id = int(cmd[0])

#         subject_name, professor = manager_search_subject_by_id(subjects, subject_id)
#         print(f"{subject_id}. {subject_name} (professor: {professor})")


#     def ui_search_name(
#         students: list, subjects: list[list], cmd: list[str]
#     ) -> None:
#         if len(cmd) != 1:
#             raise Exception("Invalid command arguments.")

#         student_name = cmd[0].strip()

#         student_list = manager_search_name(students, student_name)

#         print(f"\nThe students that have the name '{student_name}' are:")
#         print(manager_print_students(student_list))


#     def ui_search_subject_by_name(
#         students: list, subjects: list[list], cmd: list[str]
#     ) -> None:
#         if len(cmd) != 1:
#             raise Exception("Invalid command arguments.")

#         subject_name = cmd[0].strip()

#         subject_list = manager_search_subject_by_name(subjects, subject_name)

#         print(f"\nThe subjects that have the name '{subject_name}' are:")
#         print(manager_print_subjects(subject_list))


#     def ui_search_subject_by_prof(
#         students: list, subjects: list[list], cmd: list[str]
#     ) -> None:
#         if len(cmd) != 1:
#             raise Exception("Invalid command arguments.")

#         professor = cmd[0].strip()

#         subject_list = manager_search_subject_by_prof(subjects, professor)

#         print(f"\nThe subjects that have the professor '{professor}' are:")
#         print(manager_print_subjects(subject_list))
