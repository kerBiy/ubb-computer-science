# Dându-se numărul natural n, determina numerele prime p1 si p2 astfel ca
# n = p1 + p2
# (verificarea ipotezei lui Goldbach). Pentru ce fel de n exista soluție?


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


def goldBach(n: int) -> tuple:
    if n <= 2 or n % 2 != 0:
        raise Exception("It must be an even number bigger than 4")

    for p1 in range(2, n // 2 + 1):
        p2 = n - p1
        if isPrim(p1) and isPrim(p2):
            return p1, p2


n = int(input("Enter a even number that is bigger than 4: "))
p1, p2 = goldBach(n)
print(f"The two numbers are: {p1} and {p2}")

'''
Test cases:
4: 2 + 2
3: -
2: -
18: 13 + 5
21: -
'''
