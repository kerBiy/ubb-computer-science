"""
Să se determine ultimul (din punct de vedere alfabetic) cuvânt care poate apărea într-un text care conține mai multe cuvinte separate prin ” ” (spațiu). De ex. ultimul (dpdv alfabetic) cuvânt din ”Ana are mere rosii si galbene” este cuvântul "si".
"""


def last_word(text: str) -> str:
    """
    Finds the last word in alphabetical order from agiven text.
    :param text: A string containing words separated by spaces.
    :return: The last word in alphabetical order.
    """

    max_word = ""

    for word in text.split():
        if word > max_word:
            max_word = word

    return max_word


def test_last_word():
    assert last_word("Ana are mere rosii si galbene") == "si"
    assert last_word("zebra apple banana") == "zebra"
    assert last_word("hello world") == "world"
    assert last_word("alpha beta gamma delta") == "gamma"
    assert last_word("") == ""  
    assert last_word("singleword") == "singleword"  

    print("Tests for my code passed")


test_last_word()

"""
Time Complexity Analysis:
- Splitting the string into words takes O(n), where n is the length of the text.
- Finding the maximum alphabetically among words takes O(m), where m is the number of words.
- Overall complexity: O(n + m), which is approximately O(n) for large inputs.

Space Complexity Analysis:
- Storing the words in a list requires O(m) space.
- The function uses O(m) additional space, so total space complexity is O(m).
"""
