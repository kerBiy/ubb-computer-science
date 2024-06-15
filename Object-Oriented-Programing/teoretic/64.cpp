#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Iter;

template <typename T>
class Catalog {
   private:
    std::vector<T> items;
    std::string name;

   public:
    Catalog(const std::string &name) : name(name) {}

    Catalog &operator=(const Catalog &catalog) {
        if (this == &catalog) {
            return *this;
        }

        items = catalog.items;
        name = catalog.name;
        return *this;
    }

    Catalog &operator+(const T &item) {
        items.push_back(item);
        return *this;
    }

    friend class Iter<T>;

    Iter<T> begin() { return Iter<T>(*this); }
    Iter<T> end() { return Iter<T>(*this, items.size()); }
};

template <typename T>
class Iter {
   private:
    Catalog<T> &catalog;
    size_t index;

   public:
    Iter(Catalog<T> &cat, size_t index = 0) : catalog(cat), index(index) {}

    T &operator*() { return catalog.items[index]; }

    Iter &operator++() {
        index++;
        return *this;
    }

    bool operator!=(const Iter &other) { return index != other.index; }
};

int main() {
    Catalog<int> cat{"OOP"};  // creaza catalog cu note intregi
    cat + 10;                 // adauga o nota in catalog
    cat = cat + 8 + 6;
    int sum = 0;
    for (auto n : cat) {
        sum += n;
    }  // itereaza notele din catalog
    std::cout << "Suma note:" << sum << "\n";
}