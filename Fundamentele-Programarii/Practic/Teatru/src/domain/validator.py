from domain.entity import TheatricalPiece


class ValidationError(Exception):
    pass


class Validator:
    @staticmethod
    def validate_theatrical_piece(entity: TheatricalPiece) -> None:
        error = ""

        if entity.name == "":
            error += "The name is empty\n"
        if entity.director == "":
            error += "The director name is empty\n"
        if entity.genera not in ["Drama", "Action"]:
            error += "The genera doesn't exist\n"
        if entity.screen_time <= 0:
            error += "The screen time is not valid\n"

        if error:
            raise ValidationError(error[:-1])


def test_validator() -> None:
    new_entity = TheatricalPiece("Hannibal", "Shakespeare", "Drama", 100)
    Validator.validate_theatrical_piece(new_entity)
