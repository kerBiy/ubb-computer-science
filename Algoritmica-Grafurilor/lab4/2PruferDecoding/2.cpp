#include <fstream>
#include <iostream>
#include <vector>

std::vector<int> PruferDecode(std::vector<int>& code, int n) {
    n++;
    std::vector<int> parent(n, -1);
    std::vector<int> degree(n, 1);

    for (int node : code) {
        degree[node]++;
    }

    int ptr = 0;
    while (degree[ptr] != 1) ptr++;
    int leaf = ptr;

    for (int node : code) {
        parent[leaf] = node;
        degree[node]--;
        degree[leaf]--;

        if (degree[node] == 1 && node < ptr) {
            leaf = node;
        } else {
            do {
                ptr++;
            } while (degree[ptr] != 1);
            leaf = ptr;
        }
    }
    parent[leaf] = -1;
    return parent;
}

int main() {
    std ::ifstream in("input.txt");
    std ::vector<int> v;

    int n;
    in >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        in >> x;
        v.push_back(x);
    }
    in.close();

    auto tree = PruferDecode(v, n);

    std::cout << tree.size() << "\n";
    for (auto t : tree) {
        std::cout << t << " ";
    }
    std::cout << "\n";

    return 0;
}
