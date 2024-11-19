% diferenta intre 2 multimi
% apare([E|_], E) :- !.
% apare([_|T], E) :- 
%     apare(T, E).
    

% diferenta([], _, []).
% diferenta([H|T],B, [H|Rez]) :-
%     \+ apare(B, H),
%     diferenta(T, B, Rez).
% diferenta([H|T], B, Rez) :-
%     apare(B, H),
%     diferenta(T, B, Rez).

% lungime_para([]).
% lungime_para([_, _ | T]) :-
%     lungime_para(T).

% perechi(lista, Rez)

% lipeste([], B, B).
% lipeste([H|T], B, [H|Rez]) :-
%     lipeste(T, B, Rez).


% perechi(_, [], []).
% perechi(E, [H|T], [[E, H] | Rez]) :-
%     perechi(E, T, Rez).

% lista_perechi([_], []).
% lista_perechi([H|T], Rez) :-
%     perechi(H, T, Per),
%     lista_perechi(T, Rez1),
%     lipeste(Per, Rez1, Rez).

% afla_maxim([E], E).
% afla_maxim([H|T], H) :-
%     afla_maxim(T, Rez),
%     H > Rez.
% afla_maxim([H|T], Rez) :-
%     afla_maxim(T, Rez),
%     H =< Rez.

% poz_maxim([], _, _, []).
% poz_maxim([H|T], Max, Count, [Count | Rez]) :-
%     H = Max,
%     NextCount is Count + 1,
%     poz_maxim(T, Max, NextCount, Rez).

% poz_maxim([H|T], Max, Count, Rez) :-
%     H \= Max,
%     NextCount is Count + 1,
%     poz_maxim(T, Max, NextCount, Rez).

% main(List, Rez) :-
%     afla_maxim(List, Max),
%     poz_maxim(List, Max, 1, Rez).

adauga_final([], E, [E]).
adauga_final([H|T], E, [H | Rez]) :-
    adauga_final(T, E, Rez).

reverse([], []).
reverse([H|T], Rez) :-
    reverse(T, Rez2),
    adauga_final(Rez2, H, Rez).


suma([], [], 1, [1]).
suma([], [], 0, []).
suma([H1|T1], [H2|T2], Carry, [NewSum | Rez]) :-
    Sum is H1 + H2 + Carry,
    Sum > 9,
    NewSum is Sum mod 10,
    suma(T1, T2, 1, Rez).
suma([H1|T1], [H2|T2], Carry, [Sum | Rez]) :-
    Sum is H1 + H2 + Carry,
    Sum =< 9,
    suma(T1, T2, 0, Rez).
suma([], [H|T], Carry, [NewSum | Rez]) :-
    Sum is H + Carry,
    Sum > 9,
    NewSum is Sum mod 10,
    suma([], T, 1, Rez).
suma([], [H|T], Carry, [Sum | Rez]) :-
    Sum is H + Carry,
    Sum =< 9,
    suma([], T, 0, Rez).
suma([H|T], [], Carry, [NewSum | Rez]) :-
    Sum is H + Carry,
    Sum > 9,
    NewSum is Sum mod 10,
    suma(T, [], 1, Rez).
suma([H|T], [], Carry, [Sum | Rez]) :-
    Sum is H + Carry,
    Sum =< 9,
    suma(T, [], 0, Rez).

main(List1, List2, Rez) :-
    reverse(List1, L1),
    reverse(List2, L2),
    suma(L1, L2, 0, Var),
    reverse(Var, Rez).





