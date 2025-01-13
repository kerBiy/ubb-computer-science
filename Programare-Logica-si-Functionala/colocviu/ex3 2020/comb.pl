candidat([H | _], H).
candidat([_ | T], R) :-
    candidat(T, R).

comb_aux(_, K, C, Lg, _, C) :-
    Lg = K.
    % 0 is S mod 3.

comb_aux(L, K, [H | C], Lg, S, R) :-
    candidat(L, E),
    % H > E,
    \+ candidat([H | C], E),
    Lg1 is Lg + 1,
    S1 is S + E,
    comb_aux(L, K, [E | [H | C]], Lg1, S1, R).

comb(L, K, R) :-
    candidat(L, E),
    comb_aux(L, K, [E], 1, E, R).

main(L, K, Rez) :-
    findall(Rez1, comb(L, K, Rez1), Rez).