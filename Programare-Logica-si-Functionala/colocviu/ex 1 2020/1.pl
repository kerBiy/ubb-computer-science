f([], 0).
f([H|T], S) :- S1 is S - H, f(T, S1).