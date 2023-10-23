# Calculați cel mai mare divizor comun a doua numere

a = int(input("enter the first number: "))
b = int(input("enter the secod number: "))

"""
def cmmdc(a: int, b: int) -> int:
    if b == 0:
        return a
    return cmmdc(b, a % b)
"""

if a < 0 or b < 0:
    raise Exception("Only pozitive numbers")

if a == 0:
    print(b)
elif b == 0:
    print(a)
else:
    while a != b:
        if a > b:
            a -= b
        else:
            b -= a

    print(a)
