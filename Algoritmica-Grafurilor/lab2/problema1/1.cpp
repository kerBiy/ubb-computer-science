#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using std::vector, std::queue;

class Graph {
   private:
    int nodes;
    vector<vector<int>> adj;

   public:
    Graph(int nodes) : nodes(nodes) { adj.resize(nodes); }

    void addEdge(int first_node, int second_node) {
        adj[first_node - 1].push_back(second_node - 1);
    }

    void moore(int src) {
        src--;  // The nodes are from 1 not from 0

        vector<int> dist(nodes, INT_MAX);
        queue<int> queue;

        dist[src] = 0;
        queue.push(src);

        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();

            for (int node : adj[current]) {
                if (dist[node] == INT_MAX) {
                    dist[node] = dist[current] + 1;
                    queue.push(node);
                }
            }
        }

        std::cout << "The min distance from node " << src << ":\n";
        for (int i = 0; i < nodes; ++i) {
            std::cout << "The node " << i + 1 << ": ";

            (dist[i] == INT_MAX) ? std::cout << "Infinity\n"
                                 : std::cout << dist[i] << "\n";
        }
    }
};

int main() {
    std::ifstream fin("graf.txt");
    if (!fin) {
        std::cerr << "The file graf.txt does not exist.\n";
        return 1;
    }

    int nodes, edges;
    fin >> nodes >> edges;

    Graph graph(nodes);

    for (int i = 0; i < edges; ++i) {
        int first_node, second_node;
        fin >> first_node >> second_node;
        graph.addEdge(first_node, second_node);
    }

    fin.close();

    int src;
    std::cout << "Enter the src: ";
    std::cin >> src;

    graph.moore(src);

    return 0;
}