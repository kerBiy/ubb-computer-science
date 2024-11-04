% b) Se da o lista eterogena, formata din numere intregi si liste de numere intregi. Lista incepe cu un numar si nu sunt 2 elemente consecutive care sunt liste. Se cere ca in fiecare sublista sa se adauge dupa 1-ul, al 3- lea, al 7-lea… element valoarea care se gaseste inainte de sublista in lista eterogena. De ex:
% [1, [2, 3], 7, [4, 1, 4], 3, 6, [7, 5, 1, 3, 9, 8, 2, 7], 5] => 
% [1, [2, 1, 3], 7, [4, 7, 1, 4, 7], 3, 6, [7, 6, 5, 1, 6, 3, 9, 8, 2, 6,7], 5].

% add_in_sublist(ListaInitiala: list, ListaRezultata: list)
% model de flux: I, O
% ListaInitiala - lista originala
% ListaRezultata - lista cu valorile E adaugate dupa pozitiile dorite

add_in_sublists([], []).

add_in_sublists([H1, [H2|T2]|T], [H1, NewSubList|NewT]) :-
    % Creeaza sublista noua cu elementele corecte
    add_at_positions([H2|T2], H1, 1, 1, NewSubList),
    !, % Opreste backtracking-ul aici
    % Continua procesarea pentru restul listei
    add_in_sublists(T, NewT).

add_in_sublists([H|T], [H|NewT]) :-
    % Daca elementul nu este o sublista, continua procesarea
    add_in_sublists(T, NewT).


% add_at_positions(ListaCurenta, E, PozitiaCurenta, NumarPozitieDorita, ListaRezultata)
add_at_positions([], _, _, _, []).

add_at_positions([H|T], E, CurrentPos, TargetPos, [H,E|RestResult]) :-
    CurrentPos =:= TargetPos,      % Daca pozitia curenta este target 
    NextPos is CurrentPos + 1,     % Incrementam pozitia curenta
    NewTargetPos is TargetPos * 2 + 1, % Calculam urmatoarea pozitie target 
    NewE is E * 2,
    add_at_positions(T, NewE, NextPos, NewTargetPos, RestResult).

add_at_positions([H|T], E, CurrentPos, TargetPos, [H|RestResult]) :-
    CurrentPos =\= TargetPos,      % Daca pozitia curenta nu este target 
    NextPos is CurrentPos + 1,     % Incrementam pozitia curenta
    add_at_positions(T, E, NextPos, TargetPos, RestResult).
