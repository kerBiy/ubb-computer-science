def find_last_alphabetic_word(text: str) -> str:
    """
    Finds the last word in alphabetical order from a given text.
    @param text: A string containing words separated by spaces.
    @return: The last word in alphabetical order.
    """
    words = text.split()  
    return max(words) if words else ""  


def test_find_last_alphabetic_word():
    assert find_last_alphabetic_word("Ana are mere rosii si galbene") == "si"
    assert find_last_alphabetic_word("zebra apple banana") == "zebra"
    assert find_last_alphabetic_word("hello world") == "world"
    assert find_last_alphabetic_word("alpha beta gamma delta") == "gamma"
    assert find_last_alphabetic_word("") == ""  # Edge case: empty string
    assert find_last_alphabetic_word("singleword") == "singleword"  # Single word

    print("All tests passed!")


test_find_last_alphabetic_word()

"""
Time Complexity Analysis:
- Splitting the string into words takes O(n), where n is the length of the text.
- Finding the maximum alphabetically among words takes O(m), where m is the number of words.
- Overall complexity: O(n + m), which is approximately O(n) for large inputs.

Space Complexity Analysis:
- Storing the words in a list requires O(m) space.
- The function uses O(m) additional space, so total space complexity is O(m).
"""
