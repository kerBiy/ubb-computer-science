candidat([H|_], H).
candidat([_|T], R) :- candidat(T,R).

% get_len([], 0).
% get_len([_ | T], Rez) :- 
%     get_len(T, OldRez),
%     Rez is OldRez + 1.

back_aux(_, K, C, Lg, C) :-
    % verify the condition from the problem
    Lg =< K. % for subsets
    % Lg = K. % for comb and aran

back_aux(L, K, [H | C], Lg, R) :-
    candidat(L, E),
    % \+ candidat([H | C], E), % for aran
    H > E, % for comb and subsets
    Lg1 is Lg + 1,
    back_aux(L, K, [E | [H | C]], Lg1, R).

back(L, K, R) :-
    candidat(L, E),
    back_aux(L, K, [E], 1, R).

main(L, K, Rez) :-
    % get_len(L, K), % for subsets
    findall(Rez1, back(L, K, Rez1), Rez).


