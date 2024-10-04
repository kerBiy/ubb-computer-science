from random import sample
from math import factorial
from itertools import permutations

word = "word"

permList = list(permutations(word))
for perm in permList:
    print(perm)
    
print(f"The count is {factorial(len(word))}")

print(sample(permList, 1))

    