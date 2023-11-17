class ValidatorObject:
    @staticmethod
    def validate_id(id: int) -> bool:
        return 1 <= id <= 999999

    @staticmethod
    def validate_name(name: str) -> bool:
        name_list = name.split()

        if not (2 <= len(name_list) <= 5):
            return False

        for name in name_list:
            if not (name[0].isupper() and name[1:].isalpha() and name[1:].islower()):
                return False

        return True


class ValidatorStudent(ValidatorObject):
    @classmethod
    def validate(cls, student) -> None:
        error = ""

        if not cls.validate_id(student.id):
            error += "Invalid student id number.\n"
        if not cls.validate_name(student.name):
            error += "Invalid student name.\n"

        if error:
            raise ValueError(error[:-1])


class ValidatorSubject(ValidatorObject):
    @classmethod
    def validate(cls, subject) -> None:
        error = ""

        if not cls.validate_id(subject.id):
            error += "Invalid subject id number.\n"
        if not cls.validate_name(subject.name):
            error += "Invalid subject name.\n"
        if not cls.validate_prof(subject.prof):
            error += "Invalid subject professor.\n"

        if error:
            raise ValueError(error[:-1])

    @staticmethod
    def validate_name(name: str) -> bool:
        if not (1 <= len(name.split()) <= 8):
            return False

        return name[0].isupper()

    @classmethod
    def validate_prof(cls, professor: str) -> bool:
        return super().validate_name(professor)
