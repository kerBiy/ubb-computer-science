#include <fstream>
#include <iostream>
#include <vector>

#define INF 9999
#define NIL -1

typedef std::pair<int, int> Pair;

class Graph {
   private:
    int nodes;
    std::vector<std::vector<Pair>> adjList;
    std::vector<int> parent;
    std::vector<int> dist;
    std::vector<int> unweighted_dist;

   public:
    Graph(int nodes) : nodes(nodes) {
        adjList.resize(nodes);
        dist.resize(nodes, INF);
        parent.resize(nodes, NIL);
        unweighted_dist.resize(nodes, INF);
    }

    std::vector<int> getDistance() { return dist; }

    void addEdge(int u, int v, int w) { adjList[u].push_back({v, w}); }

    std::vector<int> findPath(int src) {
        int count = unweighted_dist[src];
        std::vector<int> path(count + 1);
        path[count] = src;

        for (int i = count; i > 0; --i) {
            path[i - 1] = parent[path[i]];
        }

        return path;
    }

    bool bellmanFordAlg(int src) {
        parent[src] = src;
        dist[src] = 0;
        unweighted_dist[src] = 0;

        for (int u = 0; u < nodes; ++u) {
            for (const auto& edge : adjList[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] != INF && dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                }

                if (unweighted_dist[u] != INF &&
                    unweighted_dist[v] > unweighted_dist[u] + 1) {
                    unweighted_dist[v] = unweighted_dist[u] + 1;
                }
            }
        }

        for (int u = 0; u < nodes; ++u) {
            for (const auto& edge : adjList[u]) {
                int v = edge.first;
                int weight = edge.second;
                if (dist[u] != INF && dist[v] > dist[u] + weight) {
                    return false;
                }
            }
        }

        return true;
    }
};

int main() {
    std::ifstream fin("input.txt");

    int nodes, edges;
    fin >> nodes >> edges;

    Graph graph(nodes);

    for (int i = 0; i < edges; ++i) {
        int u, v, w;
        fin >> u >> v >> w;
        graph.addEdge(u, v, w);
    }

    int src, dst;
    fin >> src >> dst;

    fin.close();

    if (!graph.bellmanFordAlg(src)) {
        std::cout << "Graph contains negative weight cycle\n";
        return 1;
    }

    auto distance = graph.getDistance();
    if (distance[dst] != INF) {
        auto path = graph.findPath(dst);
        for (auto node : path) {
            std::cout << node << " ";
        }
    } else {
        std::cout << "NO PATH\n";
    }

    return 0;
}