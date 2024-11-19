% colors/1 - culorile disponibile pentru colorarea tarilor
colors([red, green, blue]). 

% neighbor/2 - relatia de vecinatate intre doua tari
% neighbor(Country1, Country2) inseamna ca Country1 si Country2 sunt vecine
neighbor(country1, country2).
neighbor(country2, country3).
neighbor(country3, country4).
neighbor(country1, country4).
neighbor(country1, country3).

% color_map(Countries: list, Coloring: list)
% model de flux: (I, O)
% Countries: lista cu tarile de colorat
% Coloring: lista de perechi (Country, Color) care reprezinta solutia finala a colorarii
% color_map coloreaza lista de tari astfel incat nicio tara vecina sa nu fie colorata la fel
color_map(Countries, Coloring) :-
    colors(Colors),
    assign_colors(Countries, Colors, Coloring),
    valid_coloring(Coloring).

% assign_colors(Countries: list, Colors: list, Coloring: list)
% model de flux: (I, I, O)
% Countries: lista de tari care urmeaza sa fie colorate
% Colors: lista de culori disponibile
% Coloring: lista rezultat care contine perechi (Country, Color)
% assign_colors parcurge fiecare tara din Countries si ii atribuie o culoare din lista Colors
assign_colors([], _, []).
assign_colors([Country|RestCountries], Colors, [(Country, Color)|RestColoring]) :-
    member(Color, Colors),
    assign_colors(RestCountries, Colors, RestColoring).

% valid_coloring(Coloring: list)
% model de flux: (I)
% Coloring: lista de perechi (Country, Color) cu toate tarile colorate
% valid_coloring verifica daca solutia de colorare este valida (adica nicio tara vecina nu are aceeasi culoare)
valid_coloring([]).
valid_coloring([(Country, Color)|RestColoring]) :-
    \+ (member((Neighbor, Color), RestColoring),
    neighbor(Country, Neighbor)),
    valid_coloring(RestColoring).

main(List, Solutions) :-
    findall(Coloring, color_map(List, Coloring), Solutions).