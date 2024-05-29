#include <fstream>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

typedef std::pair<int, int> Edge;
typedef std::vector<std::vector<Edge>> Graph;

int Prim(const Graph& graph, int src, int v, std::vector<Edge>& mst_edges) {
    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;
    std::vector<bool> inMST(v, false);
    std::vector<int> parent(v, -1);
    int mst_cost = 0;

    pq.push({0, src});

    while (!pq.empty()) {
        int weight = pq.top().first;
        int vertex = pq.top().second;
        pq.pop();

        if (inMST[vertex]) continue;

        mst_cost += weight;
        inMST[vertex] = true;

        if (parent[vertex] != -1) {
            mst_edges.push_back({parent[vertex], vertex});
        }

        for (const auto& edge : graph[vertex]) {
            int next_vertex = edge.second;
            int next_weight = edge.first;
            if (!inMST[next_vertex]) {
                pq.push({next_weight, next_vertex});
                parent[next_vertex] = vertex;
            }
        }
    }
    return mst_cost;
}

int main() {
    std::ifstream in("input.txt");

    int v, e;
    in >> v >> e;
    Graph graph(v);

    for (int i = 0; i < e; ++i) {
        int x, y, w;
        in >> x >> y >> w;
        graph[x].push_back({w, y});
        graph[y].push_back({w, x});
    }
    in.close();

    std::vector<Edge> mst_edges;
    int total_weight = Prim(graph, 0, v, mst_edges);

    std::cout << total_weight << "\n";
    std::cout << mst_edges.size() << "\n";
    for (const auto& edge : mst_edges) {
        std::cout << edge.first << " " << edge.second << "\n";
    }

    return 0;
}
