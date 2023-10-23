# Generați cel mai mare număr perfect mai mic decât un număr dat. Daca nu exista un astfel de număr, tipăriți un mesaj. Un număr este perfect daca este egal cu suma divizorilor proprii. Ex. 6 este un număr perfect (6=1+2+3)
def divSum(n: int) -> int:
    sum = 0
    for i in range(1, n):
        if n % i == 0:
            sum += i

    return sum


def firstPerfectNum(n: int):
    while n > 5:
        if divSum(n) == n:
            return n
        n -= 1

    return "not existent"


n = int(input("Enter a number: "))
print(f"First perfect number before {n} is {firstPerfectNum(n)}")
