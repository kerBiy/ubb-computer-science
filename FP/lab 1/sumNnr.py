# Calculați suma a n numere naturale
n = int(input("Enter a number: "))

sum = 0
for i in range(n):
    num = int(input(f"Eter {i + 1} number: "))
    if num < 0:
        raise Exception("Sorry, no numbers below zero")
    sum += num

print(sum)

