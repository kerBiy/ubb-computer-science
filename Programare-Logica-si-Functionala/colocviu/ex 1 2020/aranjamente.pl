candidat([H|_], H).
candidat([_|T], R) :- candidat(T,R).

aran_aux(_, K, P, C, Lg, Pr, C) :-
    Lg = K,
    Pr = P.

aran_aux(L, K, P, C, Lg, Pr, R) :-
    candidat(L, E),
    \+ candidat(C, E),
    Lg1 is Lg + 1,
    Pr1 is Pr * E,
    aran_aux(L, K, P, [E|C], Lg1, Pr1, R).

aran(L, K, P, R) :-
    candidat(L, E),
    aran_aux(L, K, P, [E], 1, E, R).

main(L, K, P, Rez) :-
    findall(Rez1, aran(L, K, P, Rez1), Rez).


