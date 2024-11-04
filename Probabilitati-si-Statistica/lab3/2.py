from random import randrange
from matplotlib.pyplot import bar, hist, grid, show, legend

data = [randrange(?,?) for _ in range(?)]

bin_edges = [k+0.5 for k in range(?)]

bar(?, ?, width = 0.85, color = 'red', edgecolor = 'black',
alpha= 0.6, label = 'probabilitati')

hist(?, ?, density = True, rwidth = 0.9, color = 'green', edgecolor = 'black', alpha = 0.5, label = 'frecvente relative')

distribution = dict([(?,?) for i in range(1,7)])
legend(loc = 'lower left')
grid()
show()