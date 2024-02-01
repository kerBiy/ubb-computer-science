# dubleaza fiecare elem. dintr-o nums de numere
def double(nums, left, right):
    if left == right:
        nums[left] = nums[left] * 2
        return

    mid = (left + right) // 2
    double(nums, left, mid)
    double(nums, mid + 1, right)


nums = [1, 2, 3, 4, 5, 6]
double(nums, 0, len(nums) - 1)
print(nums)
