from domain.entity import Furniture


class Validator:
    def __init__(self) -> None:
        pass

    def validate_type(self, furniture_type: str) -> bool:
        return furniture_type in [
            "corp iluminat",
            "spatiu depozitare",
            "canapea",
            "scaun",
        ]

    def validate_stock(self, stock: int) -> bool:
        return stock >= 0

    def validate_price(self, price: float) -> bool:
        return price >= 0

    def validate_item(self, item: Furniture) -> bool:
        if not self.validate_type(item.type):
            return False
        if not self.validate_stock(item.stock):
            return False
        if not self.validate_price(item.price):
            return False

        return True

    def validate_all_codes(self, items: list[Furniture]) -> bool:
        code_set = set()

        for item in items:
            if item.code not in code_set:
                code_set.add(item.code)
            else:
                return False

        return True

    def validate_all(self, items: list[Furniture]) -> bool:
        for item in items:
            if not self.validate_item(item):
                return False

        if not self.validate_all_codes(items):
            return False

        return True
