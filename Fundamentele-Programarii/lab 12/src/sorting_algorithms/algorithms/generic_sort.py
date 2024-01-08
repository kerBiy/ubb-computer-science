class GenericSort:
    def __init__(self, iterable, key, reverse, cmp):
        self.__iterable = iterable
        self.__key = key
        self.__reverse = reverse
        self.__cmp = cmp

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
    def cmp(self):
        return self.__cmp

    @cmp.setter
    def cmp(self, cmp):
        self.__cmp = cmp

    @property
    def reverse(self) -> bool:
        return self.__reverse

    def sort(self) -> None:
        # This is an abstract method for the child classes
        pass

    def _in_order(self, first_element, second_element) -> bool:
        """
        It compares the two elements given as arguments
        input: 2 arguments of any data type
        output: True if the elements are in order, False otherwise
        """
        if self.key is None and self.cmp is None:
            self.key = lambda x: x
        elif self.key is not None and self.cmp is not None:
            self.cmp = None

        if self.key is not None:
            if self.key(first_element) == self.key(second_element):
                return True
            if not self.reverse:
                return self.key(first_element) < self.key(second_element)
            return self.key(first_element) > self.key(second_element)
        elif self.cmp is not None:
            if self.cmp(first_element, second_element) == 0:
                return True
            if not self.reverse:
                return self.cmp(first_element, second_element) == -1
            return self.cmp(first_element, second_element) == 1
