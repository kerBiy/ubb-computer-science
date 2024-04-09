#include <fstream>
#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

const int INF =
    numeric_limits<int>::max();  // Infinity value for unreachable vertices

struct Edge {
    int source, dest, weight;
};

class Graph {
   private:
    int V, E;
    vector<Edge> edges;

   public:
    Graph(int V, int E) : V(V), E(E) {}

    void addEdge(int source, int dest, int weight) {
        edges.push_back({source, dest, weight});
    }

    // Function to read graph from input file
    void readGraphFromFile(const string& filename) {
        ifstream infile(filename);
        if (!infile) {
            cerr << "Error: Unable to open input file." << endl;
            exit(1);
        }

        infile >> V >> E;
        edges.clear();
        for (int i = 0; i < E; ++i) {
            int source, dest, weight;
            infile >> source >> dest >> weight;
            addEdge(source, dest, weight);
        }

        infile.close();
    }

    // Function to write distances matrix and updated edges to output file
    void writeOutputToFile(const vector<vector<int>>& distances) {
        // Write updated edges
        for (const auto& edge : edges) {
            cout << edge.source << " " << edge.dest << " " << edge.weight
                 << endl;
        }

        // Write distances matrix
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (distances[i][j] == INF) {
                    cout << "INF ";
                } else {
                    cout << distances[i][j] << " ";
                }
            }
            cout << endl;
        }
    }
};

int main() {
    string input_file = "input.txt";

    Graph graph(0, 0);  // Initialize an empty graph
    graph.readGraphFromFile(input_file);

    // graph.writeOutputToFile(distances);

    return 0;
}
