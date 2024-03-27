#include <iostream>
#include <vector>

using std::vector;

class Graph {
    int nodes;
    vector<vector<int>> adj;

   public:
    Graph(int nodes) : nodes(nodes) { adj.resize(nodes); }

    void addEdge(int u, int v) { adj[u - 1].push_back(v - 1); }

    void DFS_VISIT(int u, vector<bool> &visited) {
        visited[u] = true;
        std::cout << u + 1 << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                DFS_VISIT(v, visited);
            }
        }
    }

    void DFS() {
        vector<bool> visited(nodes, false);

        for (int i = 0; i < nodes; ++i) {
            if (!visited[i]) {
                DFS_VISIT(i, visited);
            }
        }
    }
};

int main() {
    Graph graph(6);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);

    std::cout << "Varfurile descoperite de DFS: ";
    graph.DFS();
    std::cout << '\n';

    return 0;
}
