import os


def readArray(array: list[int]) -> None:
    input_string = input("Enter values: ")
    input_list = input_string.split()
    array[:] = [int(item) for item in input_list]


def printArray(nums: list[int]) -> None:
    print(f"The current array is: {nums}")


def findLongestSubSeq(condition, nums: list[int]) -> list[int]:
    max_length, curr_length = 0, 1
    start_index = start_max = 0

    for i in range(1, len(nums)):
        if condition(nums[i], nums[i - 1]):
            curr_length += 1
        else:
            if curr_length > max_length:
                max_length = curr_length
                start_max = start_index

            curr_length = 1
            start_index = i

    if curr_length > max_length:
        max_length = curr_length
        start_max = start_index

    return nums[start_max : start_max + max_length]


def beEqual(a: int, b: int) -> bool:
    return a == b


def haveOppositeSign(a: int, b: int) -> bool:
    return (a < 0) != (b < 0)


def longest3DistinctSubSeq(nums: list[int]) -> list[int]:
    if not nums:
        return []

    curr_seq = [nums[0]]
    max_seq = [nums[0]]

    for i in range(1, len(nums)):
        curr_seq.append(nums[i])

        while len(set(curr_seq)) > 3:
            curr_seq.pop(0)

        if len(curr_seq) > len(max_seq):
            max_seq[:] = curr_seq

    return max_seq


def printEqualSeq(nums: list[int]) -> None:
    res = findLongestSubSeq(beEqual, nums)
    print(f"\nThe longest subsequence with only equal elements is: {res}")


def printOppositeSignSeq(nums: list[int]) -> None:
    res = findLongestSubSeq(haveOppositeSign, nums)
    print(f"\nThe longest subsequence with only opposite sign elements is: {res}")


def print3DistinctSeq(nums: list[int]) -> None:
    res = longest3DistinctSubSeq(nums)
    print(f"\nThe longest subsequence that contains max 3 distinct elements is: {res}")


def testEqualElem() -> None:
    # TEST 0: Empty List
    assert findLongestSubSeq(beEqual, []) == []
    # TEST 1: Different Numbers
    assert findLongestSubSeq(beEqual, [4, 8, 10, 14, 16]) == [4]
    # TEST 2: Mixed List
    assert findLongestSubSeq(beEqual, [5, 5, 3, 4, 4, 4, 2]) == [4, 4, 4]
    # TEST 3: All list
    assert findLongestSubSeq(beEqual, [3, 3, 3, 3, 3]) == [3, 3, 3, 3, 3]
    # TEST 4: Two sequence with the same number of elements
    assert findLongestSubSeq(beEqual, [2, 2, 2, 5, 5, 7, 7, 7, 8]) == [2, 2, 2]


def testOppositeSigns() -> None:
    # TEST 0: Empty List
    assert findLongestSubSeq(haveOppositeSign, []) == []
    # TEST 1: Pozitive Nums
    assert findLongestSubSeq(haveOppositeSign, [4, 8, 10, 14, 16]) == [4]
    # TEST 2: Mixed List
    assert findLongestSubSeq(haveOppositeSign, [5, -5, 3, 4, 4, -4, 2]) == [5, -5, 3]
    # TEST 3: All elemnets list
    assert findLongestSubSeq(haveOppositeSign, [3, -3, 3, -3, 3]) == [3, -3, 3, -3, 3]


def test3Distinct() -> None:
    # TEST 0: Empty List
    assert longest3DistinctSubSeq([]) == []
    # TEST 1: One number list
    assert longest3DistinctSubSeq([2]) == [2]
    # TEST 2: mixed list
    assert longest3DistinctSubSeq([2, 3, 2, 5]) == [2, 3, 2, 5]
    # TEST 3: long list
    assert longest3DistinctSubSeq([2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 5]) == [
        3,
        3,
        3,
        4,
        4,
        4,
        5,
        5,
        5,
        5,
    ]
    # TEST 4: Random case
    assert longest3DistinctSubSeq([2, 3, 4, 5, 5, 2, 2, 3]) == [4, 5, 5, 2, 2]


def testFunction() -> None:
    testEqualElem()
    testOppositeSigns()
    test3Distinct()
    print("All tests pass")


def optionMenu() -> None:
    print("\nOPTION MENU:")
    print("Enter 1 for reading an array")
    print("Enter 2 for printing the current array")
    print("Enter 3 for finding the longest equal subsequence")
    print("Enter 4 for finding the longest opposite signs subsequence")
    print(
        "Enter 5 for finding the longest subseqence that has maximum 3 distinct elements"
    )
    print("Enter q for exiting the program")


def consoleApp() -> None:
    array = []
    options = {
        1: readArray,
        2: printArray,
        3: printEqualSeq,
        4: printOppositeSignSeq,
        5: print3DistinctSeq,
    }

    while True:
        optionMenu()
        usser_input = input("Enter an option: ")
        os.system("clear")

        if usser_input == "q":
            print("Exiting the program...")
            break

        try:
            usser_input = int(usser_input)
            options[usser_input](array)
        except ValueError:
            print("Invalid input.")
        except KeyError:
            print("This option is not yet implemented.")


if __name__ == "__main__":
    testFunction()
    consoleApp()
