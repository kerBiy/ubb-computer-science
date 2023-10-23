# Găsiți cel mai mare număr prim mai mic decât un număr dat. Daca nu exista un astfel de număr, tipăriți un mesaj.


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


def beforePrime(n: int):
    while n > 1:
        if isPrim(n):
            return n
        n -= 1

    return "not existent"


number = int(input("Enter a number: "))
print(f"The biggest prime number smaller than {n} is {beforePrime(n)}")
