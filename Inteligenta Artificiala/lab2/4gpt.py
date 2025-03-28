from collections import Counter


def unique_words(text: str) -> list:
    """
    Finds words that appear exactly once in a given text.
    :param text: A string containing words separated by spaces.
    :return: A list of words that appear exactly once.
    """
    words = text.split()  # Split text into words
    word_counts = Counter(words)  # Count occurrences of each word

    return [word for word, count in word_counts.items() if count == 1]


def test_unique_words():
    assert set(unique_words("ana are ana are mere rosii ana")) == {"mere", "rosii"}
    assert set(unique_words("apple banana apple orange banana kiwi")) == {
        "orange",
        "kiwi",
    }
    assert set(unique_words("one two three four five six seven eight nine ten")) == {
        "one",
        "two",
        "three",
        "four",
        "five",
        "six",
        "seven",
        "eight",
        "nine",
        "ten",
    }
    assert set(unique_words("repeat repeat repeat")) == set()
    assert set(unique_words("")) == set()
    print("All tests passed!")


test_unique_words()

"""
Time Complexity Analysis:
- Splitting the text into words takes O(n), where n is the length of the text.
- Counting word occurrences takes O(m), where m is the number of words.
- Filtering unique words takes O(m).
- Overall complexity: O(n + m), which simplifies to O(n).

Space Complexity Analysis:
- Storing the word counts requires O(m) space.
- The final output list requires O(m) space in the worst case.
- Total space complexity: O(m).
"""
