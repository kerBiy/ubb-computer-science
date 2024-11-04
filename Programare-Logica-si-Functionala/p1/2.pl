% Flux: I, O: lista, rezultat

% Cazul de baza: lista goala returneaza lista goala.
adauga_dupa_par([], []).

% Cazul in care elementul X este par.
adauga_dupa_par([X|T], [X, 1|Rez]) :-
    X mod 2 =:= 0,  % Verificam daca X este par.
    adauga_dupa_par(T, Rez).

% Cazul in care elementul X este impar.
adauga_dupa_par([X|T], [X|Rez]) :-
    X mod 2 =\= 0,  % Verificam daca X este impar.
    adauga_dupa_par(T, Rez).