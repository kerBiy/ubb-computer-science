#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

#define INF 9999

using std::priority_queue;
using std::vector;

typedef std::pair<int, int> pair;

class Graph {
   private:
    int nodes;
    vector<vector<pair>> adj;

    vector<int> distance;
    vector<bool> visited;

   public:
    Graph(int nodes) : nodes(nodes) {
        adj.resize(nodes);
        distance.resize(nodes, INF);
        visited.resize(nodes, false);
    }

    void addEdge(int first_node, int second_node, int weight) {
        adj[first_node].push_back({second_node, weight});
    }

    void dijkstra(int src) {
        priority_queue<pair, vector<pair>, std::greater<pair>> pq;

        distance[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (visited[u]) continue;

            visited[u] = true;

            for (const auto &neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (distance[v] > distance[u] + weight) {
                    distance[v] = distance[u] + weight;
                    pq.push({distance[v], v});
                }
            }
        }

        for (int i = 0; i < nodes; ++i) {
            std::cout << "Shortest distance from node " << src << " to node "
                      << i << " is " << distance[i] << '\n';
        }
    }
};

int main() {
    std::ifstream fin("graf.txt");

    int nodes, edges, src;
    fin >> nodes >> edges >> src;

    Graph graph(nodes);

    for (int i = 0; i < edges; ++i) {
        int first, second, weight;
        fin >> first >> second >> weight;

        graph.addEdge(first, second, weight);
    }

    graph.dijkstra(src);

    fin.close();
    return 0;
}
