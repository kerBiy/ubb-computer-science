# verificați daca un număr citit de la tastatura este prim

n = int(input("enter a number: "))
is_prim = True

if n <= 1:
    is_prim = False
elif n != 2 and n % 2 == 0:
    is_prim = False

for i in range(3, n, 2):
    if n % i == 0:
        is_prim = False

print(is_prim)
