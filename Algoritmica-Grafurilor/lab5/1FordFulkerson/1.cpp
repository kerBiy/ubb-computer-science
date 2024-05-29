#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stack>
#include <vector>

const int INF = 1000000000;

bool dfs(int s, int t, const std::vector<std::vector<int>>& capacity,
         std::vector<int>& parent, std::vector<std::vector<int>>& residual) {
    std::fill(parent.begin(), parent.end(), -1);
    parent[s] = s;
    std::stack<std::pair<int, int>> stk;
    stk.push({s, INF});

    while (!stk.empty()) {
        int cur = stk.top().first;
        int flow = stk.top().second;
        stk.pop();

        for (int i = 0; i < capacity.size(); ++i) {
            if (parent[i] == -1 && residual[cur][i] > 0) {
                parent[i] = cur;
                int new_flow = std::min(flow, residual[cur][i]);
                if (i == t) {
                    return new_flow;
                }
                stk.push({i, new_flow});
            }
        }
    }

    return 0;
}

int fordFulkerson(int s, int t, std::vector<std::vector<int>>& capacity) {
    int flow = 0;
    int new_flow;
    std::vector<int> parent(capacity.size());
    std::vector<std::vector<int>> residual = capacity;

    while ((new_flow = dfs(s, t, capacity, parent, residual))) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            residual[prev][cur] -= new_flow;
            residual[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

int main() {
    std::ifstream input("input.txt");

    if (!input.is_open()) {
        std::cerr << "Error opening input file\n";
        return 1;
    }

    int nodes, edges;
    input >> nodes >> edges;

    std::vector<std::vector<int>> capacity(nodes, std::vector<int>(nodes, 0));

    for (int i = 0; i < edges; i++) {
        int x, y, c;
        input >> x >> y >> c;
        capacity[x][y] += c;
    }

    input.close();

    int source = 0;
    int sink = nodes - 1;

    int max_flow = fordFulkerson(source, sink, capacity);
    std::cout << max_flow << std::endl;

    return 0;
}
