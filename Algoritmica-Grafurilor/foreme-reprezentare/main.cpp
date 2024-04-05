#include <fstream>
#include <iostream>
#include <vector>

typedef std::vector<std::vector<int>> Graph;
typedef std::vector<int> Vector;
typedef std::vector<std::pair<int, int>> List;

Graph fromLEtoAM() {
    std::ifstream fin("edgeList.txt");

    int num_nodes;
    fin >> num_nodes;

    Graph output(num_nodes, Vector(num_nodes, 0));

    int node1, node2;
    while (fin >> node1 >> node2) {
        output[node1 - 1][node2 - 1] = 1;
        output[node2 - 1][node1 - 1] = 1;
    }

    fin.close();
    return output;
}

List fromAMtoLE(Graph adjMat) {
    List output;
    int num_nodes = adjMat.size();

    for (int i = 0; i < num_nodes; ++i) {
        for (int j = i + 1; j < num_nodes; ++j) {
            if (adjMat[i][j] == 1) {
                output.push_back({i + 1, j + 1});
            }
        }
    }

    return output;
}

Graph fromLEtoAL() {
    std::ifstream fin("edgeList.txt");

    int num_nodes;
    fin >> num_nodes;

    Graph output(num_nodes);

    int node1, node2;
    while (fin >> node1 >> node2) {
        output[node1 - 1].push_back(node2);
        output[node2 - 1].push_back(node1);
    }

    fin.close();
    return output;
}

int main() {
    auto adjMat = fromLEtoAM();

    std::cout << "Form edge list to adj matrix:\n";
    for (auto x : adjMat) {
        for (auto y : x) {
            std::cout << y << ' ';
        }
        std::cout << '\n';
    }

    auto edList = fromAMtoLE(adjMat);

    std::cout << "Form adj matrix to list of edges:\n";
    for (auto x : edList) {
        std::cout << x.first << ' ' << x.second << '\n';
    }

    auto adjList = fromLEtoAL();

    std::cout << "Form edge list to adj matrix:\n";
    for (size_t i = 0; i < adjList.size(); ++i) {
        std::cout << i + 1 << ": ";
        for (auto x : adjList[i]) {
            std::cout << x << ' ';
        }
        std::cout << '\n';
    }

    return 0;
}
