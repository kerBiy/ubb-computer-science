#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

#define INF 9999
#define NIL -1

class Graph {
   private:
    int nodes;
    std::vector<std::vector<int>> adjList;
    std::vector<int> distance;
    std::vector<int> parent;

   public:
    Graph(int nodes) : nodes(nodes) {
        adjList.resize(nodes);
        distance.resize(nodes, INF);
        parent.resize(nodes, NIL);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    std::vector<int> findPath(int src) {
        int count = distance[src];
        std::vector<int> path(count + 1);
        path[count] = src;

        for (int i = count; i > 0; --i) {
            path[i - 1] = parent[path[i]];
        }

        return path;
    }

    void mooreAlg(int src) {
        std::queue<int> queue;

        distance[src] = 0;
        queue.push(src);

        while (!queue.empty()) {
            int current = queue.front();
            queue.pop();

            for (int node : adjList[current]) {
                if (distance[node] == INF) {
                    parent[node] = current;
                    distance[node] = distance[current] + 1;
                    queue.push(node);
                }
            }
        }

        for (int i = 0; i < nodes; ++i) {
            if (distance[i] == 0) {
                continue;
            }

            std::cout << "For node " << i << " the path is: ";

            if (distance[i] != INF) {
                auto path = findPath(i);
                for (auto node : path) {
                    std::cout << node << " ";
                }
            } else {
                std::cout << "NO PATH";
            }

            std::cout << std::endl;
        }
    }

    void printAdjList() {
        for (int i = 0; i < nodes; ++i) {
            std::cout << "Node " << i << ": ";
            for (auto node : adjList[i]) {
                std::cout << node << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    std::ifstream fin("moore.txt");
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

    graph.mooreAlg(src);

    std::cout << "Done\n";

    return 0;
}