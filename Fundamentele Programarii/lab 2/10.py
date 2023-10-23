# Pentru un număr natural n dat găsiți numărul natural minim m format cu aceleași cifre. Ex. n=3658, m=3568.


def minNumber(n: int) -> int:
    freq = [0] * 10

    while n:
        freq[n % 10] += 1
        n //= 10

    new_number = 0
    for i in range(10):
        for j in range(freq[i]):
            new_number = new_number * 10 + i

    return new_number


n = int(input("Enter a number: "))
print(f"The minimum number that can form from the digits of {n} is {minNumber(n)}")
