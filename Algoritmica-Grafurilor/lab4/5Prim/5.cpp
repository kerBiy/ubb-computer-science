#include <fstream>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

typedef std::pair<int, int> Edge;

int Prim(const std::vector<std::vector<Edge>> &graph, int src) {
    int v = graph.size();
    std::vector<bool> visited(v, false);
    std::priority_queue<Edge, std::vector<Edge>, std::greater<>> pq;

    pq.push({0, src});
    int cost = 0;
    int tree_edges = 0;

    while (!pq.empty() && tree_edges < v - 1) {
        int weight = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;
        cost += weight;
        tree_edges++;

        for (const auto &edge : graph[u]) {
            int next_weight = edge.first;
            int v = edge.second;
            if (!visited[v]) {
                pq.push({next_weight, v});
            }
        }
    }

    return cost;
}

int main() {
    std::ifstream in("input.txt");

    int v, e;
    in >> v >> e;
    std::vector<std::vector<Edge>> graph(v);

    for (int i = 0; i < e; ++i) {
        int x, y, w;
        in >> x >> y >> w;
        graph[x].push_back({w, y});
        graph[y].push_back({w, x});
    }

    in.close();

    int src = 0;
    int cost = Prim(graph, src);

    std::cout << cost << "\n";

    return 0;
}
