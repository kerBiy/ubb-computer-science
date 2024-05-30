#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

#define NIL -1

typedef std::pair<int, int> Edge;
typedef std::vector<std::vector<Edge>> Graph;
typedef std::vector<Edge> Tree;

int Prim(Graph graph, int src, int nodes, Tree& mst) {
    std::priority_queue<Edge, Tree, std::greater<Edge>> queue;
    std::vector<bool> found(nodes, false);
    std::vector<int> parent(nodes, NIL);

    int total_cost = 0;
    queue.push({0, src});

    while (!queue.empty()) {
        int weight = queue.top().first;
        int vertex = queue.top().second;
        queue.pop();

        if (found[vertex]) continue;

        total_cost += weight;
        found[vertex] = true;

        if (parent[vertex] != NIL) {
            mst.push_back({parent[vertex], vertex});
        }

        for (const auto& edge : graph[vertex]) {
            int next_vertex = edge.second;
            int next_weight = edge.first;

            if (!found[next_vertex]) {
                queue.push({next_weight, next_vertex});
                parent[next_vertex] = vertex;
            }
        }
    }
    return total_cost;
}

int main() {
    std::ifstream fileIn("input3.txt");

    int nodes, edges;
    fileIn >> nodes >> edges;
    Graph graph(nodes);

    for (int i = 0; i < edges; ++i) {
        int x, y, w;
        fileIn >> x >> y >> w;
        graph[x].push_back({w, y});
        graph[y].push_back({w, x});
    }
    fileIn.close();

    Tree mst;
    int total_weight = Prim(graph, 0, nodes, mst);

    std::cout << total_weight << "\n";
    std::cout << mst.size() << "\n";
    for (const auto& edge : mst) {
        std::cout << edge.first << " " << edge.second << "\n";
    }

    return 0;
}
