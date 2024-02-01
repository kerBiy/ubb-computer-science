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


def quick(nums, left, right):
    if left >= right:
        return

    index = partition(nums, left, right)
    quick(nums, left, index - 1)
    quick(nums, index + 1, right)


nums = [4, 7, 5, 3, 2, 6]
quick(nums, 0, 5)
print(nums)
