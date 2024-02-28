#include <iostream>
#include <fstream>
#include <vector>

using std::vector;

void printMatrix(const vector<vector<int>> &matrix)
{
    for (const auto &row : matrix)
    {
        for (int val : row)
            std::cout << val << ' ';

        std::cout << '\n';
    }
}

void printAdjacencyList(const vector<vector<int>> &adjacencyList)
{
    for (size_t i = 0; i < adjacencyList.size(); ++i)
    {
        std::cout << i + 1 << ": ";

        for (const int j : adjacencyList[i])
            std::cout << j + 1 << " ";

        std::cout << '\n';
    }
}

vector<vector<int>> transformIntoAdjacencyList(const vector<vector<int>> &adjacencyMatrix, int numNodes)
{
    vector<vector<int>> adjacencyList(numNodes);

    for (int i = 0; i < numNodes; ++i)
        for (int j = 0; j < numNodes; ++j)
            if (adjacencyMatrix[i][j] == 1)
                adjacencyList[i].push_back(j);

    return adjacencyList;
}

vector<vector<int>> transformIntoIncidenceMatrix(const vector<vector<int>> &adjacencyMatrix, int numNodes, int numEdges)
{
    vector<vector<int>> incidenceMatrix(numNodes, vector<int>(numEdges, 0));
    int edgeIndex = 0;

    for (int i = 0; i < numNodes; ++i)
    {
        for (int j = i + 1; j < numNodes; ++j)
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

    int numNodes, numEdges;
    fin >> numNodes >> numEdges;

    vector<vector<int>> adjacencyMatrix(numNodes, vector<int>(numNodes, 0));

    for (int i = 0; i < numEdges; ++i)
    {
        int first_node, second_node;
        fin >> first_node >> second_node;

        adjacencyMatrix[first_node - 1][second_node - 1] = 1;
        adjacencyMatrix[second_node - 1][first_node - 1] = 1;
    }

    std::cout << "Matricea de adiacenta:\n";
    printMatrix(adjacencyMatrix);

    fin.close();

    vector<vector<int>> adjacencyList = transformIntoAdjacencyList(adjacencyMatrix, numNodes);

    std::cout << "\nLista de adiacenta:\n";
    printAdjacencyList(adjacencyList);

    vector<vector<int>> incidenceMatrix = transformIntoIncidenceMatrix(adjacencyMatrix, numNodes, numEdges);

    std::cout << "\nMatricea de incidenta:\n";
    printMatrix(incidenceMatrix);

    return 0;
}