#include <iostream>
#include <fstream>
#include <vector>

using std::vector;

void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (auto val : row)
            std::cout << val << ' ';

        std::cout << '\n';
    }
}

void printAdjacencyList(const vector<vector<int>> &adjacencyList)
{
    for (int i = 0; i < adjacencyList.size(); ++i)
    {
        std::cout << i + 1 << ": ";

        for (const int j : adjacencyList[i])
            std::cout << j + 1 << " ";

        std::cout << '\n';
    }
}

vector<vector<int>> transformIntoAdjacencyList(const vector<vector<int>> &adjacencyMatrix, int nodes)
{
    vector<vector<int>> adjacencyList(nodes);

    for (int i = 0; i < nodes; ++i)
        for (int j = 0; j < nodes; ++j)
            if (adjacencyMatrix[i][j] == 1)
                adjacencyList[i].push_back(j);

    return adjacencyList;
}

vector<vector<int>> transformIntoIncidenceMatrix(const vector<vector<int>> &adjacencyMatrix, int nodes, int edges)
{
    vector<vector<int>> incidenceMatrix(nodes, vector<int>(edges, 0));
    int edgeIndex = 0;

    for (int i = 0; i < nodes; ++i)
    {
        for (int j = i + 1; j < nodes; ++j)
        {
            if (adjacencyMatrix[i][j] == 1)
            {
                incidenceMatrix[i][edgeIndex] = 1;
                incidenceMatrix[j][edgeIndex] = 1;
                ++edgeIndex;
            }
        }
    }

    return incidenceMatrix;
}

int main()
{
    std::ifstream fin("in.txt");

    int nodes, edges;
    fin >> nodes >> edges;

    vector<vector<int>> adjacencyMatrix(nodes, vector<int>(nodes, 0));

    for (int i = 0; i < edges; ++i)
    {
        int first_node, second_node;
        fin >> first_node >> second_node;

        adjacencyMatrix[first_node - 1][second_node - 1] = 1;
        adjacencyMatrix[second_node - 1][first_node - 1] = 1;
    }

    std::cout << "Matricea de adiacenta:\n";
    printMatrix(adjacencyMatrix);

    fin.close();

    vector<vector<int>> adjacencyList = transformIntoAdjacencyList(adjacencyMatrix, nodes);

    std::cout << "\nLista de adiacenta:\n";
    printAdjacencyList(adjacencyList);

    vector<vector<int>> incidenceMatrix = transformIntoIncidenceMatrix(adjacencyMatrix, nodes, edges);

    std::cout << "\nMatricea de incidenta:\n";
    printMatrix(incidenceMatrix);

    return 0;
}