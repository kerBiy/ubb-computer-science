#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using std::vector, std::queue;

class Graph {
    int nodes;
    vector<vector<int>> adj;

   public:
    Graph(int nodes) : nodes(nodes), adj(nodes) { adj.resize(nodes); }

    void addEdge(int v, int w) {
        adj[v - 1].push_back(w - 1);
        adj[w - 1].push_back(v - 1);
    }

    void bfs(int src) {
        src--;

        vector<bool> visited(nodes, false);
        vector<int> distance(nodes, -1);

        queue<int> q;
        q.push(src);

        visited[src] = true;
        distance[src] = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            std::cout << u + 1 << " (distance: " << distance[u] << ")\n";

            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                    distance[v] = distance[u] + 1;
                }
            }
        }
    }
};

int main() {
    std::ifstream fin("graf.txt");
    int nodes, edges;
    fin >> nodes >> edges;

    Graph graph(nodes);

    for (int i = 0; i < edges; ++i) {
        int v, w;
        fin >> v >> w;

        graph.addEdge(v, w);
    }

    int source;
    fin >> source;

    graph.bfs(source);

    return 0;
}
