#include <fstream>
#include <iostream>
#include <set>
#include <vector>

std::vector<int> PruferCode(std::vector<int>& parent, int n) {
    std::vector<int> degree(n, 0);
    std::set<int> leaves;
    std::vector<int> code;

    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            degree[parent[i]]++;
        }
    }
    for (int i = 0; i < n; i++) {
        if (degree[i] == 0 && parent[i] != -1) {
            leaves.insert(i);
        }
    }

    while (code.size() <= n - 2) {
        int leaf = *leaves.begin();
        leaves.erase(leaves.begin());
        int p = parent[leaf];
        code.push_back(p);
        if (--degree[p] == 0 && parent[p] != -1) {
            leaves.insert(p);
        }
    }

    return code;
}

int main() {
    std ::ifstream in("input.txt");

    int n;
    in >> n;

    std::vector<int> parent;
    std::vector<int> code;

    for (int i = 0; i < n; i++) {
        int x;
        in >> x;
        parent.push_back(x);
    }

    code = PruferCode(parent, n);

    std::cout << code.size() << "\n";
    for (const auto& l : code) {
        std::cout << l << " ";
    }

    in.close();
    return 0;
}
