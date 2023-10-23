# Fie n un număr natural dat. Calculați produsul p al tuturor factorilor proprii ai lui n.
def prodFactoriPrimi(n: int) -> int:
    prod = 1
    factor = 2

    while n > 1:
        if n % factor == 0:
            prod *= factor
            while n % factor == 0:
                n //= factor
        factor += 1

    return prod


n = int(input("Enter a number: "))
p = prodFactoriPrimi(n)
print(f"The result is: {p}")
