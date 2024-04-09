#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

#define INF 9999
typedef std::pair<int, int> pair;

class Graph {
   private:
    int nodes;
    std::vector<std::vector<pair>> adjList;
    std::vector<int> dist;

   public:
    Graph(int nodes) : nodes(nodes) {
        adjList.resize(nodes);
        dist.resize(nodes, INF);
    }

    void addEdge(int u, int v, int w) { adjList[u].push_back({v, w}); }

    bool bellmanFordAlg(int src) {
        dist[src] = 0;

        for (int u = 0; u < nodes; ++u) {
            for (const auto& edge : adjList[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                }
            }
        }

        for (int u = 0; u < nodes; ++u) {
            for (const auto& edge : adjList[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] != INF && dist[u] + weight < dist[v]) {
                    std::cout << "Graph contains negative weight cycle\n";
                    return false;
                }
            }
        }

        for (int i = 0; i < nodes; ++i) {
            std::cout << "From node " << i << ": " << dist[i] << "\n";
        }

        return true;
    }
};

int main() {
    std::ifstream fin("bellman-ford.txt");
    int nodes, edges, src;
    fin >> nodes >> edges >> src;

    Graph graph(nodes);

    for (int i = 0; i < edges; ++i) {
        int first_node, second_node, weight;
        fin >> first_node >> second_node >> weight;
        graph.addEdge(first_node, second_node, weight);
    }

    fin.close();

    graph.bellmanFordAlg(src);

    std::cout << "Done\n";

    return 0;
}