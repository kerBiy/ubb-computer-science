// 1. Fie un fisier ce contine un graf neorientat reprezentat sub forma : prima linie contine numarul nodurilor iar urmatoarele randuri muchiile grafului.Sa se scrie un program in C / C++ care sa citeasca fisierul si sa reprezinte / stocheze un graf folosind matricea de adiacenta, lista de adiacenta si matricea de incidenta.Sa se converteasca un graf dintr - o forma de reprezentare in alta.

#include <iostream>
#include <fstream>

void matrice_adiacenta()
{
    std::ifstream fin("in.txt");

    int graf[101][101] = {};

    int vertex, edges;
    fin >> vertex >> edges;

    for (int i = 1; i <= edges; ++i)
    {
        int first_vertex, second_vertex;
        fin >> first_vertex >> second_vertex;

        graf[first_vertex][second_vertex] = 1;
        graf[second_vertex][first_vertex] = 1;
    }

    for (int i = 1; i <= vertex; ++i, std::cout << "\n")
        for (int j = 1; j <= vertex; ++j)
            std::cout << graf[i][j] << ' ';
    std::cout << "\n";

    fin.close();
}

void lista_adiacenta()
{
    std::ifstream fin("in.txt");

    int graf[101][101] = {};

    int vertex, edges;
    fin >> vertex >> edges;

    for (int i = 1; i <= edges; ++i)
    {
        int first_vertex, second_vertex;
        fin >> first_vertex >> second_vertex;

        graf[first_vertex][graf[first_vertex][0] + 1] = second_vertex;
        graf[first_vertex][0]++;

        graf[second_vertex][graf[second_vertex][0] + 1] = first_vertex;
        graf[second_vertex][0]++;
    }

    for (int i = 1; i <= vertex; ++i, std::cout << '\n')
        for (int j = 1; j <= graf[i][0]; ++j)
            std::cout << graf[i][j] << " ";
    std::cout << "\n";

    fin.close();
}

void matrice_incidenta()
{
    std::ifstream fin("in.txt");

    int graf[101][101] = {};

    int vertex, edges;
    fin >> vertex >> edges;

    for (int i = 1; i <= edges; ++i)
    {
        int first_vertex, second_vertex;
        fin >> first_vertex >> second_vertex;

        graf[first_vertex][i] = 1;
        graf[second_vertex][i] = 1;
    }

    for (int i = 1; i <= vertex; ++i, std::cout << "\n")
        for (int j = 1; j <= edges; ++j)
            std::cout << graf[i][j] << ' ';
    std::cout << "\n";

    fin.close();
}

int main()
{
    matrice_adiacenta();
    lista_adiacenta();
    matrice_incidenta();

    return 0;
}