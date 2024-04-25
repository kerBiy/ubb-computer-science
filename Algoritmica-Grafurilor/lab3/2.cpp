#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

const int INF = 1000000;
using std::priority_queue;
typedef std::pair<int, int> pair;

class Graph {
    std::string in;
    std::string out;

    int nodes;
    int edges;
    std::vector<std::vector<pair>> adjList;

   public:
    Graph(std::string in, std::string out) {
        this->in = in;
        this->out = out;
        std::ifstream fin(this->in);

        if (!fin) {
            std::cout << "Fisierul de intrare nu a putut fi deschis!\n";
            exit(-1);
        }

        int nodes, edges;
        fin >> nodes >> edges;
        this->adjList.resize(nodes);
        this->nodes = nodes;
        this->edges = edges;

        for (int i = 0; i < edges; ++i) {
            int u, v, w;
            fin >> u >> v >> w;
            adjList[u].push_back({v, w});
        }

        fin.close();
    }

    void dijkstra(int src) {
        priority_queue<pair, std::vector<pair>, std::greater<>> queue;
        std::vector<int> distance(nodes, INF);

        distance[src] = 0;
        queue.push({0, src});

        while (!queue.empty()) {
            int current = queue.top().second;
            queue.pop();

            for (const auto& neighbor : adjList[current]) {
                int node = neighbor.first;
                int weight = neighbor.second;

                if (distance[node] > distance[current] + weight) {
                    distance[node] = distance[current] + weight;
                    queue.push({distance[node], node});
                }
            }
        }

        std::ofstream out_file(out, std::ios_base::app);

        for (int i = 0; i < nodes; ++i) {
            if (distance[i] == INF) {
                out_file << "INF ";
            } else {
                out_file << distance[i] << " ";
            }
        }
        out_file << "\n";
    }

    bool bellmanFord() {
        struct edge {
            int src, dest, weight;
        };

        std::vector<edge> edges;
        std::vector<int> dist(nodes, INF);
        dist[nodes] = 0;

        for (int i = 0; i < nodes; ++i) {
            edges.push_back({nodes, i, 0});
            for (auto j : adjList[i]) {
                edges.push_back({i, j.first, j.second});
            }
        }

        for (int i = 0; i < nodes; ++i) {
            for (auto j : edges) {
                if (dist[j.src] != INF &&
                    dist[j.dest] > dist[j.src] + j.weight) {
                    dist[j.dest] = dist[j.src] + j.weight;
                }
            }
        }

        for (auto j : edges) {
            if (dist[j.src] + j.weight < dist[j.dest]) {
                return false;
            }
        }

        std::ofstream out_file(out);
        for (int i = 0; i < nodes; ++i) {
            for (auto j : adjList[i]) {
                j.second += dist[i] - dist[j.first];
                out_file << i << " " << j.first << " " << j.second << "\n";
            }
        }

        out_file.close();
        return true;
    }

    void johnson() {
        if (bellmanFord() == false) {
            std::ofstream out_file(out);
            out_file << "-1\n";
            out_file.close();
            return;
        }

        for (int i = 0; i < nodes; ++i) {
            dijkstra(i);
        }
    }
};

int main() {
    Graph G("input.txt", "output.txt");
    G.johnson();
    return 0;
}
