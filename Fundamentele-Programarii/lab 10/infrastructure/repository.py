class Repository:
    def __init__(self, items_list: dict = None):
        if not items_list:
            self.__items = {}
        else:
            self.__items = items_list

    def __len__(self) -> int:
        return len(self.__items)

    def __eq__(self, another_repo) -> bool:
        return self.__items == another_repo.__items

    @property
    def get_all(self) -> list:
        return list(self.__items.values())

    def add(self, new_item) -> None:
        self.__items[new_item.id] = new_item

    def delete(self, item_id: int) -> None:
        del self.__items[item_id]

    def modify(self, item_id: int, new_item) -> None:
        self.__items[item_id] = new_item

    def search_id(self, item_id):
        return self.__items.get(item_id, None)
