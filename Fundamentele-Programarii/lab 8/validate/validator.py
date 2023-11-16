class ValidatorObject:
    def validate_id(self, id: int) -> bool:
        return 1 <= id <= 999999

    def validate_name(self, name: str) -> bool:
        name_list = name.split()

        if not (2 <= len(name_list) <= 5):
            return False

        for name in name_list:
            if not (name[0].isupper() and name[1:].isalpha() and name[1:].islower()):
                return False

        return True


class ValidatorStudent(ValidatorObject):
    def validate(self, student) -> None:
        error = ""

        if not self.validate_id(student.id):
            error += "Invalid student id number.\n"
        if not self.validate_name(student.name):
            error += "Invalid student name.\n"

        if error:
            raise ValueError(error[:-1])


class ValidatorSubject(ValidatorObject):
    def validate(self, subject) -> None:
        error = ""

        if not self.validate_id(subject.id):
            error += "Invalid subject id number.\n"
        if not self.validate_name(subject.name):
            error += "Invalid subject name.\n"
        if not self.validate_prof(subject.prof):
            error += "Invalid subject professor.\n"

        if error:
            raise ValueError(error[:-1])

    def validate_name(self, name: str) -> bool:
        if not (1 <= len(name.split()) <= 8):
            return False

        return name[0].isupper()

    def validate_prof(self, professor: str) -> bool:
        return self.validate_name(professor)