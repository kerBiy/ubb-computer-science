#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

#define INF 9999

class Graph {
   private:
    int nodes;
    std::vector<std::vector<int>> adjList;
    std::vector<bool> visited;

   public:
    Graph(int nodes) : nodes(nodes) {
        adjList.resize(this->nodes);
        visited.resize(this->nodes, false);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void bfs(int src = 0) {
        std::queue<int> queue;
        queue.push(src);

        visited[src] = true;

        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();

            std::cout << current << " ";

            for (int neighbor : adjList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.push(neighbor);
                }
            }
        }
    }
};

int main() {
    std::ifstream fin("bfs.txt");
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

    std::cout << "The order of the bfs from " << src << ": ";
    graph.bfs(src);

    std::cout << "Done\n";

    return 0;
}
