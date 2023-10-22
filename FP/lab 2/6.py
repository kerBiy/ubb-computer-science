# Găsește cel mai mic număr m din șirul lui Fibonacci definit de f[0]=f[1]=1, f[n]=f[n-1]+f[n-2], pentru n>2, mai mare decât numărul natural n dat, deci exista k astfel ca f[k]=m si m>n.


def fibo(limit: int) -> int:
    a, b = 1, 1
    while b <= limit:
        a, b = b, a + b

    return b


n = int(input("Enter a number: "))
print(f"The smallest number bigger than {n} is {fibo(n)}")
