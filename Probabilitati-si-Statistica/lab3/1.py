from random import sample
from math import comb, perm

num_simulations = 100000

red_balls = 5
blue_balls = 3
green_balls = 2
total_balls = red_balls + blue_balls + green_balls

urn = ["R"] * red_balls + ["B"] * blue_balls + ["G"] * green_balls

count_A = 0
count_B_and_A = 0

for _ in range(num_simulations):
    draw = sample(urn, 3)

    event_A = "R" in draw
    event_B = all(ball == draw[0] for ball in draw)

    if event_A:
        count_A += 1
        if event_B:
            count_B_and_A += 1

P_B_given_A = count_B_and_A / count_A if count_A != 0 else 0
print(f"P(B|A) prin simulare: {P_B_given_A :.4f}")

prob_no_red = comb(5, 0) * comb(5, 3) / comb(total_balls, 3)
prob_A = 1 - prob_no_red

prob_all_red = comb(5, 3) / comb(total_balls, 3)
prob_A_and_B = prob_all_red

P_B_given_A = prob_A_and_B / prob_A if prob_A != 0 else 0
print(f"P(B|A) matematic: {P_B_given_A :.4f}")
