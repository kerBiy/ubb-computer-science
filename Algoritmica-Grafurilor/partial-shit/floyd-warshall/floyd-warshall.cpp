#include <fstream>
#include <iostream>
#include <vector>

#define INF 9999

class Graph {
   private:
    int nodes;
    std::vector<std::vector<int>> dist;

   public:
    Graph(int nodes) : nodes(nodes) {
        dist.resize(nodes, std::vector<int>(nodes, INF));
        for (int i = 0; i < nodes; ++i) {
            dist[i][i] = 0;
        }
    }

    void addEdge(int u, int v) {
        dist[u][v] = 1;
        // dist[v][u] = 1;
    }

    void floydWarshallAlg() {
        for (int k = 0; k < nodes; ++k) {
            for (int i = 0; i < nodes; ++i) {
                for (int j = 0; j < nodes; ++j) {
                    if (dist[i][k] != INF && dist[k][j] != INF &&
                        dist[i][j] > dist[i][k] + dist[k][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        std::cout << "Shortest distances between every pair of vertices:\n";
        for (int i = 0; i < nodes; ++i) {
            for (int j = 0; j < nodes; ++j) {
                if (dist[i][j] == INF) {
                    std::cout << "INF\t";
                } else {
                    std::cout << dist[i][j] << "\t";
                }
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    std::ifstream fin("floyd-warshall.txt");
    int nodes, edges;
    fin >> nodes >> edges;

    Graph graph(nodes);

    for (int i = 0; i < edges; ++i) {
        int first_node, second_node;
        fin >> first_node >> second_node;
        graph.addEdge(first_node, second_node);
    }

    fin.close();

    graph.floydWarshallAlg();

    std::cout << "Done\n";

    return 0;
}
