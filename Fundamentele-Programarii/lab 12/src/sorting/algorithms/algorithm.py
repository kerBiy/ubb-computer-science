from enum import Enum, unique

from sorting.algorithms.selection_sort import SelectionSort
from sorting.algorithms.shake_sort import ShakeSort


@unique
class Algorithm(Enum):
    SELECTION_SORT = SelectionSort
    SHAKE_SORT = ShakeSort
