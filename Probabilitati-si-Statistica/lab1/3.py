from random import sample
from math import perm, comb
from itertools import permutations, combinations

def function(type, word, k=0, numar_total=False, aleator=False):
    match type:
        case "combinari":
            if numar_total:
                return comb(len(word), k) 
            
            combList = list(combinations(word, k))
            
            if aleator:
                return sample(combList, 1) 
            
            return combList
        
        case "aranjamente":
            if numar_total:
                return perm(len(word), k) 
            
            aList = list(permutations(word, k))
            
            if aleator:
                return sample(aList, 1) 
            
            return aList 
        
        case "permutari":
            if numar_total:
                return perm(len(word)) 
            
            permList = list(permutations(word))
            
            if aleator:
                return sample(permList, 1) 
            
            return permList 

def main():
    print("Combinari:")
    print(function("combinari", "word", 2))
    print(function("combinari","word", 2, numar_total=True))
    print(function("combinari","word", 2, aleator=True))

    print("Aranjamente:")
    print(function("aranjamente", "word", 2))
    print(function("aranjamente","word", 2, numar_total=True))
    print(function("aranjamente","word", 2, aleator=True))
    
    print("Permutari")
    print(function("permutari", "word"))
    print(function("permutari","word", numar_total=True))
    print(function("permutari","word", aleator=True))
    

main()