#include <fstream>
#include <iostream>
#include <list>
#include <stack>
#include <vector>

class EulerianCycle {
   public:
    EulerianCycle(int n) : adj(n) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    std::vector<int> findEulerianCycle() {
        std::vector<int> cycle;
        std::vector<bool> visitedEdge(adj.size(), false);
        std::stack<int> currentPath;
        std::list<int> circuit;

        int u = 0;
        currentPath.push(u);

        while (!currentPath.empty()) {
            if (!adj[u].empty()) {
                currentPath.push(u);
                int v = adj[u].back();
                adj[u].pop_back();

                auto it = std::find(adj[v].begin(), adj[v].end(), u);
                if (it != adj[v].end()) {
                    adj[v].erase(it);
                }

                u = v;
            } else {
                circuit.push_front(u);
                u = currentPath.top();
                currentPath.pop();
            }
        }

        for (int node : circuit) {
            cycle.push_back(node);
        }

        return cycle;
    }

   private:
    std::vector<std::list<int>> adj;
};

int main() {
    std::ifstream input("input.txt");
    if (!input.is_open()) {
        std::cerr << "Error opening input file\n";
        return 1;
    }

    int V, E;
    input >> V >> E;
    EulerianCycle ec(V);

    for (int i = 0; i < E; ++i) {
        int x, y;
        input >> x >> y;
        ec.addEdge(x, y);
    }
    input.close();

    std::vector<int> cycle = ec.findEulerianCycle();

    for (size_t i = 0; i < cycle.size() - 1; ++i) {
        std::cout << cycle[i];
        if (i != cycle.size() - 1) {
            std::cout << " ";
        }
    }
    std::cout << std::endl;

    return 0;
}
