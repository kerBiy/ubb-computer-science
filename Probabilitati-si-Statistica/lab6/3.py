from scipy.stats import uniform
from numpy import exp, mean
from scipy.integrate import quad


def g(x):
    return exp(-(x**2))


# Limitele integralei
a, b = -1, 3

# Metoda Monte Carlo
n = 100000
u = uniform.rvs(a, b - a, size=n)
monte_carlo_integral = (b - a) * mean(g(u))

# Valoarea exacta
exact_integral, _ = quad(g, a, b)

print(f"Valoarea aproximata folosind Monte Carlo: {monte_carlo_integral:.6f}")
print(f"Valoarea exacta: {exact_integral:.6f}")
