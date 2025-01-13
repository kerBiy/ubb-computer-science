from scipy.stats import expon, uniform
from numpy import mean, std, multiply, where, random

p1, p2 = 0.4, 0.6

lambda1 = 1 / 5
a, b = 4, 6

n = 100000
t1 = expon.rvs(scale=1 / lambda1, size=n)
t2 = uniform.rvs(a, b - a, size=n)
t_total = where(random.rand(n) < p1, t1, t2)

# a) Media si deviatia standard
mean_t = mean(t_total)
std_t = std(t_total)

# b) Probabilitatea empirica ca timpul sa fie < 5 secunde
p_empirical = mean(t_total < 5)

# c) Probabilitatea teoretica
p_teoretic = p1 * expon.cdf(5, scale=1 / lambda1) + p2 * uniform.cdf(5, a, b - a)

print(f"Media timpului de printare: {mean_t:.2f} secunde")
print(f"Deviatia standard a timpului de printare: {std_t:.2f} secunde")
print(f"Probabilitatea empirica (T < 5): {p_empirical:.4f}")
print(f"Probabilitatea teoretica (T < 5): {p_teoretic:.4f}")
