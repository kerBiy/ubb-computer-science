#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using std ::make_pair;
using std ::pair;
using std ::vector;

class UnionFind {
   private:
    vector<int> parent, rank;

   public:
    explicit UnionFind(int size) : parent(size), rank(size, 0) {
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    };
    int find_nod(int nod) {
        int root = nod;
        while (root != parent[root]) {
            root = parent[root];
        }
        while (nod != root) {
            int next = parent[nod];
            parent[nod] = root;
            nod = next;
        }
        return root;
    }
    void reuniune(int nod1, int nod2) {
        int rad1 = find_nod(nod1);
        int rad2 = find_nod(nod2);
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

auto tree_sort(vector<pair<pair<int, int>, int>>& tree) {
    sort(tree.begin(), tree.end(),
         [](pair<pair<int, int>, int> element_1,
            pair<pair<int, int>, int> element_2) {
             return element_1.second < element_2.second;
         });
    return tree;
}

auto Kruskal(vector<pair<pair<int, int>, int>>& tree, int numar_nod) {
    vector<pair<pair<int, int>, int>> T;
    UnionFind union_find(numar_nod);
    for (const auto& t : tree) {
        int nod1 = t.first.first;
        int nod2 = t.first.second;
        if (union_find.find_nod(nod1) != union_find.find_nod(nod2)) {
            union_find.reuniune(nod2, nod1);
            auto m = make_pair(t.first, t.second);
            T.push_back(m);
            if (T.size() == numar_nod - 1) {
                break;
            }
        }
    }
    return T;
}

int main() {
    std ::ifstream in("input.txt");

    vector<pair<pair<int, int>, int>> tree;
    int v, e;
    in >> v >> e;
    for (int i = 0; i < e; i++) {
        int x, y, w;
        in >> x >> y >> w;
        auto extremitati = make_pair(x, y);
        auto element = make_pair(extremitati, w);
        tree.push_back(element);
    }
    auto tr = tree_sort(tree);
    auto T = Kruskal(tr, v);

    int sum = 0;
    for (const auto& t : T) {
        sum = sum + t.second;
    }
    std::cout << sum << "\n";
    std::cout << T.size() << "\n";
    for (const auto& t : T) {
        std::cout << t.first.first << " " << t.first.second << " " << "\n";
    }

    in.close();
    return 0;
}
