from itertools import combinations_with_replacement
import math

for comb in list(combinations_with_replacement("ABCDE", 4)):
    print(" ".join(comb))
    
print(len(list(combinations_with_replacement("ABCDE", 4))))

