class GenericSort:
    def __init__(self, iterable, key, reverse):
        self.__iterable = iterable
        self.__key = key
        self.__reverse = reverse

    @property
    def iterable(self):
        return self.__iterable

    @property
    def key(self):
        return self.__key

    @key.setter
    def key(self, key):
        self.__key = key

    @property
    def reverse(self) -> bool:
        return self.__reverse

    def sort(self) -> None:
        pass

    def _cmp(self, first_element, second_element) -> bool:
        if self.key is None:
            self.key = lambda x: x

        if not self.reverse:
            return self.key(first_element) < self.key(second_element)
        return self.key(first_element) > self.key(second_element)
