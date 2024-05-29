#include <algorithm>
#include <climits>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

const int INF = INT_MAX;

class PreflowPush {
   public:
    PreflowPush(int n)
        : n(n),
          excess(n, 0),
          height(n, 0),
          capacity(n, std::vector<int>(n, 0)),
          flow(n, std::vector<int>(n, 0)),
          active(n, false) {}

    void addEdge(int u, int v, int c) { capacity[u][v] = c; }

    int getMaxFlow(int source, int sink) {
        initialize(source);
        while (!excessNodes.empty()) {
            int u = excessNodes.front();
            excessNodes.pop();
            active[u] = false;
            discharge(u);
        }
        return excess[sink];
    }

   private:
    int n;
    std::vector<int> excess;
    std::vector<int> height;
    std::vector<std::vector<int>> capacity;
    std::vector<std::vector<int>> flow;
    std::queue<int> excessNodes;
    std::vector<bool> active;

    void initialize(int source) {
        height[source] = n;
        for (int v = 0; v < n; ++v) {
            if (capacity[source][v] > 0) {
                flow[source][v] = capacity[source][v];
                flow[v][source] = -flow[source][v];
                excess[v] = flow[source][v];
                excess[source] -= flow[source][v];
                if (v != source && v != n - 1) {
                    excessNodes.push(v);
                    active[v] = true;
                }
            }
        }
    }

    void push(int u, int v) {
        int delta = std::min(excess[u], capacity[u][v] - flow[u][v]);
        if (height[u] > height[v] && delta > 0) {
            flow[u][v] += delta;
            flow[v][u] -= delta;
            excess[u] -= delta;
            excess[v] += delta;
            if (!active[v] && excess[v] > 0 && v != n - 1) {
                excessNodes.push(v);
                active[v] = true;
            }
        }
    }

    void relabel(int u) {
        int minHeight = INF;
        for (int v = 0; v < n; ++v) {
            if (capacity[u][v] - flow[u][v] > 0) {
                minHeight = std::min(minHeight, height[v]);
            }
        }
        if (minHeight < INF) {
            height[u] = minHeight + 1;
        }
    }

    void discharge(int u) {
        for (int v = 0; excess[u] > 0 && v < n; ++v) {
            push(u, v);
        }
        if (excess[u] > 0) {
            relabel(u);
            for (int v = 0; excess[u] > 0 && v < n; ++v) {
                push(u, v);
            }
        }
        if (excess[u] > 0 && !active[u]) {
            excessNodes.push(u);
            active[u] = true;
        }
    }
};

int main() {
    std::ifstream input("input.txt");
    if (!input.is_open()) {
        std::cerr << "Error opening input file\n";
        return 1;
    }

    int V, E;
    input >> V >> E;
    PreflowPush pr(V);

    for (int i = 0; i < E; ++i) {
        int x, y, c;
        input >> x >> y >> c;
        pr.addEdge(x, y, c);
    }
    input.close();

    int source = 0;
    int sink = V - 1;
    int max_flow = pr.getMaxFlow(source, sink);

    std::cout << max_flow << std::endl;

    return 0;
}
