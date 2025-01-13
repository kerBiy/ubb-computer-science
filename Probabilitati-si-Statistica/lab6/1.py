from scipy.stats import norm
from numpy import mean, std, linspace, random
from matplotlib.pyplot import show, hist, grid, legend, xticks, plot

n_values = [5000]
m = 165
sigma = 10

for n in n_values:
    values = random.normal(m, sigma, n)

    hist(
        values,
        bins=14,
        range=(130, 200),
        density=True,
        alpha=0.6,
        color="blue",
        label="Frecvente relative",
    )

    x = linspace(130, 200, 1000)
    pdf = norm.pdf(x, m, sigma)
    plot(x, pdf, "r-", label="Functia de densitate")

    legend()
    grid()
    show()

    mean_val = mean(values)
    std_val = std(values)

    count = 0
    for value in values:
        if 160 <= value <= 170:
            count += 1

    proportion = count / n

    prob_teoretica = norm.cdf(170, loc=m, scale=sigma) - norm.cdf(
        160, loc=m, scale=sigma
    )

    print(f"n={n}")
    print(
        f"Media: {mean_val:.2f}, Deviatia standard: {std_val:.2f}, Proportia in [160, 170]: {proportion:.2%}, Probabilitatea teoretica: {prob_teoretica:.2f}"
    )
