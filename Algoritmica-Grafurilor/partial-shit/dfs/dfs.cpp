#include <fstream>
#include <iostream>
#include <vector>

class Graph {
   private:
    int nodes;
    std::vector<std::vector<int>> adjList;
    std::vector<bool> visited;

   public:
    Graph(int nodes) : nodes(nodes) {
        adjList.resize(nodes);
        visited.resize(nodes, false);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void dfsVisit(int src) {
        visited[src] = true;
        std::cout << src << " ";

        for (int neighbor : adjList[src]) {
            if (!visited[neighbor]) {
                dfsVisit(neighbor);
            }
        }
    }

    void dfs(int src) { dfsVisit(src); }

    void dfs() {
        for (int i = 0; i < nodes; ++i) {
            if (!visited[i]) {
                dfsVisit(i);
            }
        }
    }

    void reset() { std::fill(visited.begin(), visited.end(), false); }
};

int main() {
    std::ifstream fin("dfs.txt");
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

    std::cout << "The order of the dfs from " << src << ": ";
    graph.dfs(src);

    graph.reset();

    std::cout << "\nThe order of the dfs: ";
    graph.dfs();

    std::cout << "Done\n";

    return 0;
}
