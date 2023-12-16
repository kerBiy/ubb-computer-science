class Recursive:
    @classmethod
    def get_20_percent(cls, items: list, initial_len: int) -> None:
        if len(items) <= initial_len // 5:
            return

        items.pop()
        cls.get_20_percent(items, initial_len)
