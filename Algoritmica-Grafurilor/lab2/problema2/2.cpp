#include <fstream>
#include <iostream>
#include <vector>

using std::vector;

vector<vector<int>> getInput() {
    std::ifstream fin("in.txt");

    int nodes;
    fin >> nodes;

    vector<vector<int>> res(nodes, vector<int>(nodes, 0));

    for (int i = 0; i < nodes; ++i) {
        for (int j = 0; j < nodes; ++j) {
            fin >> res[i][j];
        }
    }

    fin.close();
    return res;
}

int getNodes() {
    std::ifstream fin("in.txt");
    int nodes;
    fin >> nodes;
    fin.close();
    return nodes;
}

void createTransitiveGraph(vector<vector<int>> &tr, int nodes) {
    for (int k = 0; k < nodes; ++k) {
        for (int i = 0; i < nodes; ++i) {
            for (int j = 0; j < nodes; ++j) {
                if (tr[i][j] == 0 && tr[i][k] == 1 && tr[k][j] == 1) {
                    tr[i][j] = 1;
                }
            }
        }
    }
}

void printGraph(vector<vector<int>> graph, int nodes) {
    for (int i = 0; i < nodes; ++i, std::cout << '\n') {
        for (int j = 0; j < nodes; ++j) {
            std::cout << graph[i][j] << " ";
        }
    }
}

int main() {
    vector<vector<int>> tr = getInput();
    int nodes = getNodes();

    createTransitiveGraph(tr, nodes);

    printGraph(tr, nodes);

    return 0;
}