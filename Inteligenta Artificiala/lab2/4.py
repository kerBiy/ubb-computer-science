# Să se determine cuvintele unui text care apar exact o singură dată în acel text. De ex. cuvintele care apar o singură dată în ”ana are ana are mere rosii ana" sunt: 'mere' și 'rosii'.


def unique(sentance: str) -> list:
    """
    Finds words that appear exactly once in a given text.
    :param text: A string containing words separated by spaces.
    :return: A list of words that appear exactly once.
    """
    freq = {}

    for word in sentance.split():
        freq[word] = freq.get(word, 0) + 1

    unique = {word for word, count in freq.items() if count == 1}
    return list(unique)


def test_unique_words():
    assert set(unique("ana are ana are mere rosii ana")) == {"mere", "rosii"}
    assert set(unique("apple banana apple orange banana kiwi")) == {
        "orange",
        "kiwi",
    }
    assert set(unique("one two three four five six seven eight nine ten")) == {
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
    assert set(unique("repeat repeat repeat")) == set()
    assert set(unique("")) == set()
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
