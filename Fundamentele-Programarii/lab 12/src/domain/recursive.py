class Recursive:
    @classmethod
    def get_20_percent(cls, items: list, initial_len: int) -> None:
        """
        It get's the first 20% of a list
        input: a list and an initial length(len(list))
        output: returns nothing but cuts from the list argument
        """
        if len(items) <= initial_len // 5:
            return

        items.pop()
        cls.get_20_percent(items, initial_len)
