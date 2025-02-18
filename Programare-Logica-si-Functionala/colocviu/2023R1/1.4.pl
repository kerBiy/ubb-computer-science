f([], 0).
f([H|T], S) :- 
    f(T, S1),
    S is S1 - H.