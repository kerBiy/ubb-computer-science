#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

class Graph {
   private:
    int nodes;
    std::vector<std::vector<int>> adjList;
    std::vector<std::vector<int>> revAdjList;

   public:
    Graph(int nodes) : nodes(nodes) {
        adjList.resize(nodes);
        revAdjList.resize(nodes);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        revAdjList[v].push_back(u);
    }

    void dfs(int node, std::vector<bool>& visited, std::stack<int>& stack) {
        visited[node] = true;

        for (int neighbor : adjList[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, stack);
            }
        }

        stack.push(node);
    }

    void dfsReverse(int node, std::vector<bool>& visited,
                    std::vector<int>& component) {
        visited[node] = true;
        component.push_back(node);

        for (int neighbor : revAdjList[node]) {
            if (!visited[neighbor]) {
                dfsReverse(neighbor, visited, component);
            }
        }
    }

    std::vector<std::vector<int>> findCTCs() {
        std::vector<bool> visited(nodes, false);
        std::stack<int> stack;

        // First DFS to fill the stack
        for (int i = 0; i < nodes; ++i) {
            if (!visited[i]) {
                dfs(i, visited, stack);
            }
        }

        // Reset visited array
        std::fill(visited.begin(), visited.end(), false);

        std::vector<std::vector<int>> CTCs;
        while (!stack.empty()) {
            int node = stack.top();
            stack.pop();

            if (!visited[node]) {
                std::vector<int> component;
                dfsReverse(node, visited, component);
                CTCs.push_back(component);
            }
        }

        return CTCs;
    }
};

int main() {
    std::ifstream fin("kosaraju.txt");
    int nodes, edges;
    fin >> nodes >> edges;

    Graph graph(nodes);

    std::cout << "Enter the edges (u v):\n";
    for (int i = 0; i < edges; ++i) {
        int u, v;
        fin >> u >> v;
        graph.addEdge(u, v);
    }

    std::vector<std::vector<int>> CTCs = graph.findCTCs();

    std::cout << "Strongly Connected Components:\n";
    for (const auto& component : CTCs) {
        for (int node : component) {
            std::cout << node << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
