# Determina numerele prime p1 si p2 gemene imediat superioare numărului natural nenul n dat. Doua numere prime p si q sunt gemene daca q-p = 2.
def isPrim(n: int) -> bool:
    if n <= 1:
        return False
    if n != 2 and n % 2 == 0:
        return False

    d = 3
    while d * d <= n:
        if n % d == 0:
            return False
        d += 2

    return True


def twinPrimeNumbers(n: int) -> tuple:
    current_num = n + 1

    while True:
        if isPrim(current_num) and isPrim(current_num + 2):
            return current_num, current_num + 2
        current_num += 1


n = int(input("Enter a number: "))
p1, p2 = twinPrimeNumbers(n)
print(f"The two prime twin numbers bigger than n are: {p1} and {p2}")

'''
Test cases:
1: 3, 5
3: 5, 7
21: 29, 31
-3: 3, 5
5: 11, 13
'''
