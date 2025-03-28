f([], [], 0).
f([H|T], [H|T], 0) :- H mod 2 =:= 1, !.
f([_|T], Rez, P) :- f(T, Rez, P1), P is P1 + 1.