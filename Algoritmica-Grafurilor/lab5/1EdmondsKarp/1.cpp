#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

const int INF = 1000000000;

bool bfs(int s, int t, const std::vector<std::vector<int>>& capacity,
         std::vector<int>& parent) {
    std::fill(parent.begin(), parent.end(), -1);
    parent[s] = s;
    std::queue<std::pair<int, int>> q;
    q.push({s, INF});

    while (!q.empty()) {
        int cur = q.front().first;
        int flow = q.front().second;
        q.pop();

        for (int i = 0; i < capacity.size(); ++i) {
            if (parent[i] == -1 && capacity[cur][i] > 0) {
                parent[i] = cur;
                int new_flow = std::min(flow, capacity[cur][i]);
                if (i == t) {
                    return new_flow;
                }
                q.push({i, new_flow});
            }
        }
    }

    return 0;
}

int edmondsKarp(int s, int t, std::vector<std::vector<int>>& capacity) {
    int flow = 0;
    int new_flow;
    std::vector<int> parent(capacity.size());

    while ((new_flow = bfs(s, t, capacity, parent))) {
        flow += new_flow;
        int cur = t;
        while (cur != s) {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
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

    int max_flow = edmondsKarp(source, sink, capacity);
    std::cout << max_flow << std::endl;

    return 0;
}
