% Afisati toate aranjamentele de numere dintr o lista de dimensiunea K care au suma egala cu un nr dat

/*
candidat(L: list, E: elem)
L: lista din care alegem elemente
E: elementul extras din lista

Modelul de fulx: (I,I) - determinist, (I,O) - nedeterminist
Vom folosi (I,O) - nedeterminist

Modelul matematic: 

candidat(l1l2...ln) =  
    1. l1, n > 0
    2. candidat(l2...ln), n > 0
*/
candidat([H | _], H).
candidat([_ | T], R) :-
    candidat(T, R).

/*
    aran_aux(L: list, K: int, S: int, C: list, Lg: int, Sum: int, Rez: list)
    L - lista din care vrem sa extragem aranjamentele
    K - numarul de elemente intr un aranjament
    S - suma elementeleor dintr un aranjament valid
    C - lista colectoare
    Lg - lungimea listei colectoare
    Sum - suma listei colectoare
    Rez - un aranjament valid

    Modelul de flux: (I, I, I, I, I, I, O)
    Modelul matematic:

    aran_aux() =
*/
aran_aux(_, K, S, C, Lg, Sum, C) :-
    Lg = K,
    Sum = S.

aran_aux(L, K, S, C, Lg, Sum, Rez) :-
    candidat(L, E),
    \+ candidat(C, E),
    Lg1 is Lg + 1,
    Sum1 is Sum + E,
    aran_aux(L, K, S, [E | C], Lg1, Sum1, Rez).

/*
    aran(L: list, K: int, S: int, Rez: list)
    L - lista din care vrem sa extragem aranjamentele
    K - numarul de elemente intr un aranjament
    S - suma elementeleor dintr un aranjament valid
    Rez - un aranjament valid

    Modelul de flux: (I,I,I,O)
    Modelul matematic:

    aran(l1l2...ln, k, s) = ...
*/
aran(L, K, S, R) :-
    candidat(L, E),
    aran_aux(L, K, S, [E], 1, E, R).

/*
    main(L: list, K: int, S: int, Rez: list)
    L - lista din care vrem sa extragem aranjamentele
    K - numarul de elemente intr un aranjament
    S - suma elementeleor dintr un aranjament valid
    Rez - Lista cu toate aranjamentele care au lungmiea K si elementele au suma S

    Modelul de fulx: (I,I,I,O)
    Modelul matematic:

    main(l1l2...ln, k, s) = 
        findAll(aran())
*/
main(L, K, S, Rez) :-
    findall(Rez1, aran(L, K, S, Rez1), Rez).