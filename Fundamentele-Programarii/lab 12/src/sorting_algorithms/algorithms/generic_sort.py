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
        # This is an abstract method for the child classes
        pass

    def _cmp(self, first_element, second_element) -> bool:
        """
        It compares the two elements given as arguments
        input: 2 arguments of any data type
        output: True if the elements are in order, False otherwise
        """
        if self.key is None:
            self.key = lambda x: x

        if self.key(first_element) == self.key(second_element):
            return True
        if not self.reverse:
            return self.key(first_element) < self.key(second_element)
        return self.key(first_element) > self.key(second_element)
