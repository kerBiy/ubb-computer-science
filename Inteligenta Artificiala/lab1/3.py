import nltk
import os
import unicodedata
import ssl
from nltk.tokenize import sent_tokenize, word_tokenize
from nltk.corpus import wordnet

# Dezactivăm verificarea SSL pentru a permite descărcarea resurselor NLTK
ssl._create_default_https_context = ssl._create_unverified_context

# Asigurăm că avem resursele necesare
nltk.download("punkt", force=True)
nltk.download("wordnet", force=True)

# Citirea fisierului de text
file_path = "lab1/data/texts.txt"
with open(file_path, "r", encoding="utf-8") as file:
    text = file.read()

# 1. Determinarea numarului de propozitii
sentences = sent_tokenize(text)
num_sentences = len(sentences)
print("Numar de propozitii:", num_sentences)

# 2. Determinarea numarului de cuvinte
words = word_tokenize(text)
num_words = len(words)
print("Numar de cuvinte:", num_words)

# 3. Determinarea numarului de cuvinte diferite
unique_words = set(words)
num_unique_words = len(unique_words)
print("Numar de cuvinte diferite:", num_unique_words)

# 4. Determinarea celui mai scurt si celui mai lung cuvant
words_filtered = [word for word in words if word.isalpha()]
shortest_word = min(words_filtered, key=len)
longest_word = max(words_filtered, key=len)
print("Cel mai scurt cuvant:", shortest_word)
print("Cel mai lung cuvant:", longest_word)


# 5. Eliminarea diacriticelor din text
def remove_diacritics(text):
    return "".join(
        c for c in unicodedata.normalize("NFKD", text) if not unicodedata.combining(c)
    )


text_no_diacritics = remove_diacritics(text)
print("Text fara diacritice:")
print(text_no_diacritics[:500], "...")  # Afisam doar primele 500 de caractere

# 6. Determinarea sinonimelor celui mai lung cuvant
synonyms = set()
for syn in wordnet.synsets(longest_word):
    for lemma in syn.lemmas():
        synonyms.add(lemma.name())

print("Sinonime pentru cel mai lung cuvant:", synonyms)
