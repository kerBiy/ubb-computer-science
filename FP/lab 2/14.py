# Generați cel mai mic număr perfect mai mare decât un număr dat. Un număr este perfect daca este egal cu suma divizorilor proprii. Ex. 6 este un număr perfect (6=1+2+3).


def divSum(n: int) -> int:
    sum = 0
    for i in range(1, n):
        if n % i == 0:
            sum += i

    return sum


def firstPerfectNum(n: int) -> int:
    if n == divSum(n):
        return n
    return firstPerfectNum(n + 1)


n = int(input("Enter a number: "))
print(f"First perfect number after {n} is {firstPerfectNum(n)}")
