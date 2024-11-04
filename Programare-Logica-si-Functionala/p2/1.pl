% a) Se da o lista de numere intregi. Se cere sa se adauge in lista dupa 1-ul element, al 3-lea element, al 7-lea elemen, al 15-lea element … o valoare data e.

% add_after_positions(ListaInitiala : list, E : int, ListaRezultata : list)
% model de flux: I, I, O
% ListaInitiala - lista originala
% E - valoarea ce trebuie adaugata
% ListaRezultata - lista cu valorile E adaugate dupa pozitiile dorite

add_after_positions(List, E, Result) :-
    add_at_positions(List, E, 1, 1, Result).

% add_at_positions(ListaCurenta, E, PozitiaCurenta, NumarPozitieDorita, ListaRezultata)
add_at_positions([], _, _, _, []).

add_at_positions([H|T], E, CurrentPos, TargetPos, [H,E|RestResult]) :-
    CurrentPos =:= TargetPos,      % Daca pozitia curenta este target 
    NextPos is CurrentPos + 1,     % Incrementam pozitia curenta
    NewTargetPos is TargetPos * 2 + 1, % Calculam urmatoarea pozitie target 
    add_at_positions(T, E, NextPos, NewTargetPos, RestResult).

add_at_positions([H|T], E, CurrentPos, TargetPos, [H|RestResult]) :-
    CurrentPos =\= TargetPos,      % Daca pozitia curenta nu este target 
    NextPos is CurrentPos + 1,     % Incrementam pozitia curenta
    add_at_positions(T, E, NextPos, TargetPos, RestResult).

