p(10) :- !.
p(I) :- I2 is I + 1, p(I2), write(I), nl.