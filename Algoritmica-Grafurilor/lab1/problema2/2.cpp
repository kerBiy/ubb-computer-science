#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using std::vector, std::queue;

class Graph
{
private:
    vector<vector<int>> adjacencyMatrix;
    int numNodes;

public:
    Graph(int numNodes) : numNodes(numNodes)
    {
        adjacencyMatrix.resize(numNodes, vector<int>(numNodes, 0));
    }

    void addEdge(int first_node, int second_node)
    {
        adjacencyMatrix[first_node - 1][second_node - 1] = 1;
        adjacencyMatrix[second_node - 1][first_node - 1] = 1;
    }

    vector<int> findIsolatedNodes()
    {
        vector<int> isolatedNodes;

        for (size_t i = 0; i < adjacencyMatrix.size(); ++i)
        {
            bool isolated = true;

            for (const auto &element : adjacencyMatrix[i])
            {
                if (element == 1)
                {
                    isolated = false;
                    break;
                }
            }

            if (isolated)
                isolatedNodes.push_back(i + 1);
        }

        return isolatedNodes;
    }

    bool isRegularGraph()
    {
        int degree = 0;

        for (int i = 0; i < numNodes; ++i)
        {
            int nodeDegree = 0;

            for (int j = 0; j < numNodes; ++j)
                if (adjacencyMatrix[i][j] == 1)
                    nodeDegree++;

            if (i == 0)
                degree = nodeDegree;
            else if (degree != nodeDegree)
                return false;
        }
        return true;
    }

    vector<vector<int>> calculateDistanceMatrix()
    {
        vector<vector<int>> distanceMatrix = adjacencyMatrix;

        for (int k = 0; k < numNodes; ++k)
        {
            for (int i = 0; i < numNodes; ++i)
            {
                for (int j = 0; j < numNodes; ++j)
                {
                    if (distanceMatrix[i][k] && distanceMatrix[k][j])
                    {
                        if (!distanceMatrix[i][j] || distanceMatrix[i][j] > distanceMatrix[i][k] + distanceMatrix[k][j])
                        {
                            distanceMatrix[i][j] = distanceMatrix[i][k] + distanceMatrix[k][j];
                        }
                    }
                }
            }
        }

        return distanceMatrix;
    }

    bool isConnected()
    {
        vector<bool> visited(numNodes, false);
        queue<int> nodesQueue;

        nodesQueue.push(0);
        visited[0] = true;

        while (!nodesQueue.empty())
        {
            int currentNode = nodesQueue.front();
            nodesQueue.pop();

            for (int i = 0; i < numNodes; ++i)
            {
                if (adjacencyMatrix[currentNode][i] && !visited[i])
                {
                    visited[i] = true;
                    nodesQueue.push(i);
                }
            }
        }

        for (bool visit : visited)
            if (!visit)
                return false;
                
        return true;
    }
};

int main()
{
    std::ifstream fin("in.txt");

    int numNodes, numEdges;
    fin >> numNodes >> numEdges;

    Graph graph(numNodes);

    for (int i = 0; i < numEdges; ++i)
    {
        int first_node, second_node;
        fin >> first_node >> second_node;

        graph.addEdge(first_node, second_node);
    }

    fin.close();

    // a. Determinăm nodurile izolate din graf
    vector<int> isolatedNodes = graph.findIsolatedNodes();
    std::cout << "a. Noduri izolate: ";
    if (isolatedNodes.empty())
    {
        std::cout << "Nu există noduri izolate.\n";
    }
    else
    {
        for (int node : isolatedNodes)
            std::cout << node << " ";
        std::cout << '\n';
    }

    // b. Verificăm dacă graficul este regulat
    std::cout << "b. ";
    graph.isRegularGraph() ? std::cout << "Graful este regulat.\n"
                           : std::cout << "Graful nu este regulat.\n";

    // c. Calculăm matricea de distanțe
    vector<vector<int>> distanceMatrix = graph.calculateDistanceMatrix();
    std::cout << "c. Matricea de distante:\n";
    for (const auto &row : distanceMatrix)
    {
        for (int distance : row)
            std::cout << distance << " ";
        std::cout << '\n';
    }

    // d. Verificăm dacă graficul este conex
    std::cout << "d. ";
    graph.isConnected() ? std::cout << "Graful este conex.\n"
                        : std::cout << "Graful nu este conex.\n";

    return 0;
}
