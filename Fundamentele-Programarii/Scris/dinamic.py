# Cel mai lung subsir crescator


def dynamic(a):
    n = len(a)

    l = [1] * n
    p = [-1] * n

    for i in range(n - 2, -1, -1):
        for j in range(i + 1, n):
            if a[j] >= a[i] and l[i] < l[j] + 1:
                l[i] = l[j] + 1
                p[i] = j

    j = 0
    for i in range(n):
        if l[i] > l[j]:
            j = i

    res = []
    while j != -1:
        res.append(a[j])
        j = p[j]
    return res
