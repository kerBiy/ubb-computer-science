# Pentru un număr natural n dat găsiți numărul natural maxim m format cuaceleași cifre. Ex. n=3658, m=8653.
def maxNumber(n: int) -> int:
    freq = [0] * 10

    while n:
        freq[n % 10] += 1
        n //= 10

    new_number = 0
    for i in range(9, -1, -1):
        for j in range(freq[i]):
            new_number = new_number * 10 + i

    return new_number


n = int(input("Enter a number: "))
print(f"The maximum number that can form from the digits of {n} is {maxNumber(n)}")
