#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

#define INF 9999

using std::priority_queue;

typedef std::pair<int, int> pair;

class Graph {
   private:
    int nodes;
    std::vector<std::vector<pair>> adjList;

    std::vector<int> distance;
    std::vector<bool> visited;

   public:
    Graph(int nodes) : nodes(nodes) {
        adjList.resize(nodes);
        distance.resize(nodes, INF);
        visited.resize(nodes, false);
    }

    void addEdge(int u, int v, int w) { adjList[u].push_back({v, w}); }

    void dijkstraAlg(int src) {
        priority_queue<pair, std::vector<pair>, std::greater<pair>> queue;

        distance[src] = 0;
        queue.push({0, src});

        while (!queue.empty()) {
            int current = queue.top().second;
            queue.pop();

            if (visited[current]) continue;
            visited[current] = true;

            for (const auto &neighbor : adjList[current]) {
                int node = neighbor.first;
                int weight = neighbor.second;

                if (distance[node] > distance[current] + weight) {
                    distance[node] = distance[current] + weight;
                    queue.push({distance[node], node});
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
    std::ifstream fin("dijkstra.txt");
    int nodes, edges, src;
    fin >> nodes >> edges >> src;

    Graph graph(nodes);

    for (int i = 0; i < edges; ++i) {
        int first_node, second_node, weight;
        fin >> first_node >> second_node >> weight;
        graph.addEdge(first_node, second_node, weight);
    }

    fin.close();

    graph.dijkstraAlg(src);

    std::cout << "Done\n";

    return 0;
}