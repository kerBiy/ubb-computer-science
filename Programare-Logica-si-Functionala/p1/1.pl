% Flux:
% apare: I, I, lista, element cautat
% diferenta: I, I, O: multimea1, multimea2, rezultat

% Cazul de baza: daca lista este goala, elementul nu apare.
apare([], _) :- 
    false.

% Daca primul element este egal cu elementul cautat, atunci apare.
apare([X|_], X) :- 
    true.

% Daca primul element nu este cel cautat, continuam cu restul listei.
apare([_|T], E) :- 
    apare(T, E).

% Cazul de baza: daca prima multime este lista vida, rezultatul este tot lista vida.
diferenta([], _, []).

% Cazul in care elementul X apare in a doua multime, deci trebuie eliminat din rezultat.
diferenta([X|T], M2, Rez) :-
    apare(M2, X),               
    diferenta(T, M2, Rez).

% Cazul in care elementul X nu apare in a doua multime, deci il pastram in rezultat.
diferenta([X|T], M2, [X|Rez]) :-
    \+ apare(M2, X),            
    diferenta(T, M2, Rez).