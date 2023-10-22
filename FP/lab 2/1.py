# Găsiți primul număr prim mai mare decât un număr dat.
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


number = int(input("Enter a number: "))

while True:
    if isPrim(number):
        print(number)
        break
    number += 1
