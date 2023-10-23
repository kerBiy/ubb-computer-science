# Palindromul unui număr este numărul obținut prin scrierea cifrelor in ordine inversa (Ex. palindrom(237) = 732). Pentru un n dat calculați palindromul sau.
def reversed(n: int) -> int:
    rev = 0
    while n:
        rev = rev * 10 + n % 10
        n //= 10

    return rev  


n = int(input("Enter a number: "))
print(f"The reversed of {n} is {reversed(n)}")
