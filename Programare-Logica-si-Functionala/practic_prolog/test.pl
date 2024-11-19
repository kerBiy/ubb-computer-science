% combina_elem(Elem: int, Count: int, Rez: list)
% flux: I, I, O
% Elem - elementul pe care dorim sa l duplicam
% Count - de cate ori il duplicam
% Rez - lista cu elementele duplicate
combina_elem(_, 0, []).
combina_elem(E, Count, [E | Rez]) :-
    Count > 0,
    NewCount is Count - 1,
    combina_elem(E, NewCount, Rez).

% lipeste(List1: list, List2: list, Rez: list)
% flux: I, I, O
% List1 - prima lista
% List2 - a doua lista
% Rez - concatenarea listelor 
lipeste([], L, L).
lipeste([H | T], L, [H | Rez]) :-
    lipeste(T, L, Rez).

% adauga(List: list, M: int, E: int, Index: int, Count: int, Rez: list)
% flux: I, I, I, I, I, O
% List - lista initiala
% M - din cat in cat inseram
% E - elementul de inserat
% Index - pozitia pe care ne aflam
% Count - de cate ori il inseram
% Rez - lista rezultata
adauga([], _, _, _, _, []).
adauga([H | T], M, E, Index, Count, [H | Rez]) :-
    Index = M,
    NewIndex is 1,
    NewCount is Count + 1,
    combina_elem(E, Count, Combo),
    adauga(T, M, E, NewIndex, NewCount, Rez1),
    lipeste(Combo, Rez1, Rez). 
adauga([H | T], M, E, Index, Count, [H | Rez]) :-
    Index \= M,
    NewIndex is Index + 1,
    adauga(T, M, E, NewIndex, Count, Rez).

% main(List: list, M: int, E: int, Rez: list)
% flux: I, I, I, O
main(List, M, E, Rez) :- 
    adauga(List, M, E, 1, 1, Rez).
