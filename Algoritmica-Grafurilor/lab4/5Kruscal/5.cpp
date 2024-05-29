#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

class UnionFind {
   private:
    std::vector<int> parent;
    std::vector<int> rank;

   public:
    explicit UnionFind(int size) : parent(size), rank(size, 0) {
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
        }
    };

    int findNode(int node) {
        int root = node;

        while (root != parent[root]) {
            root = parent[root];
        }

        while (node != root) {
            int next = parent[node];
            parent[node] = root;
            node = next;
        }

        return root;
    }

    void unionBetweenNodes(int nod1, int nod2) {
        int rad1 = findNode(nod1);
        int rad2 = findNode(nod2);

        if (rad1 != rad2) {
            if (rank[rad1] > rank[rad2]) {
                parent[rad2] = rad1;
            } else {
                parent[rad2] = rad1;
                if (rank[rad2] == rank[rad1]) {
                    rank[rad2]++;
                }
            }
        }
    }
};

auto tree_sort(std::vector<std::pair<std::pair<int, int>, int>>& tree) {
    sort(tree.begin(), tree.end(),
         [](std::pair<std::pair<int, int>, int> element_1,
            std::pair<std::pair<int, int>, int> element_2) {
             return element_1.second < element_2.second;
         });
    return tree;
}

auto Kruskal(std::vector<std::pair<std::pair<int, int>, int>>& tree, int src) {
    std::vector<std::pair<std::pair<int, int>, int>> T;
    UnionFind union_find(src);
    for (const auto& t : tree) {
        int nod1 = t.first.first;
        int nod2 = t.first.second;
        if (union_find.findNode(nod1) != union_find.findNode(nod2)) {
            union_find.unionBetweenNodes(nod2, nod1);
            auto m = make_pair(t.first, t.second);
            T.push_back(m);
            if (T.size() == src - 1) {
                break;
            }
        }
    }
    return T;
}

int main() {
    std ::ifstream in("input.txt");
    std::vector<std::pair<std::pair<int, int>, int>> tree;

    int v, e;
    in >> v >> e;
    for (int i = 0; i < e; ++i) {
        int x, y, w;
        in >> x >> y >> w;
        auto pair = std::make_pair(x, y);
        auto element = make_pair(pair, w);
        tree.push_back(element);
    }
    in.close();

    auto tr = tree_sort(tree);
    auto T = Kruskal(tr, v);

    int sum = 0;
    for (const auto& t : T) {
        sum += t.second;
    }

    std::cout << sum << "\n";
    std::cout << T.size() << "\n";
    for (const auto& t : T) {
        std::cout << t.first.first << " " << t.first.second << " " << "\n";
    }

    return 0;
}
