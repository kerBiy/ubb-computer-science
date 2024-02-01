# Binary Search Iterative


def binary_search(nums, x):
    left, right = 0, len(nums) - 1

    while left < right:
        mid = (left + right) // 2

        if nums[mid] == x:
            return mid
        elif nums[mid] > x:
            right = mid - 1
        else:
            left = mid + 1

    return -1


# Binary Search Recursive


def binary_search_rec(nums, left, right, x):
    if left >= right:
        return -1

    mid = (left + right) // 2
    if nums[mid] == x:
        return mid
    elif nums[mid] > x:
        return binary_search_rec(nums, left, mid - 1, x)
    return binary_search_rec(nums, mid + 1, right, x)


# Bubble Sort


def bubble_sort(nums):
    is_sorted = False
    while not is_sorted:
        is_sorted = True
        for i in range(len(nums) - 1):
            if nums[i] > nums[i + 1]:
                nums[i], nums[i + 1] = nums[i + 1], nums[i]
                is_sorted = False


# Selection Sort


def selection_sort(nums):
    for i in range(len(nums) - 1):
        for j in range(i + 1, len(nums)):
            if nums[i] > nums[j]:
                nums[i], nums[j] = nums[j], nums[i]


# Insertion Sort


def insertion_sort(nums):
    for i in range(1, len(nums)):
        index = i - 1
        element = nums[i]

        while index >= 0 and element < nums[index]:
            nums[index + 1] = nums[index]
            index -= 1

        nums[index + 1] = element


# Quick Sort


def partition(nums, left, right):
    pivot = nums[left]
    i, j = left, right

    while i != j:
        while nums[j] >= pivot and i < j:
            j -= 1
        nums[i] = nums[j]

        while nums[i] <= pivot and i < j:
            i += 1
        nums[j] = nums[i]

    nums[i] = pivot
    return i


def quick_sort(nums, left, right):
    if left >= right:
        return

    index = partition(nums, left, right)
    quick_sort(nums, left, index - 1)
    quick_sort(nums, index + 1, right)


# Merge Sort


def merge_sort(nums):
    if len(nums) > 1:
        mid = len(nums) // 2

        left = nums[:mid]
        right = nums[mid:]

        merge_sort(left)
        merge_sort(right)

        i = j = k = 0

        while i < len(left) and j < len(right):
            if left[i] <= right[j]:
                nums[k] = left[i]
                i += 1
            else:
                nums[k] = right[j]
                j += 1
            k += 1

        while i < len(left):
            nums[k] = left[i]
            i += 1
            k += 1

        while j < len(right):
            nums[k] = right[j]
            j += 1
            k += 1
