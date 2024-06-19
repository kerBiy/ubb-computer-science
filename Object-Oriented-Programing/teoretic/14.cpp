#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Geanta {
   public:
    Geanta(const T& initial) { items.push_back(initial); }

    Geanta& operator+(const T& item) {
        items.push_back(item);
        return *this;
    }

    std::vector<T>::iterator begin() { return items.begin(); }

    std::vector<T>::iterator end() { return items.end(); }

   private:
    std::vector<T> items;
};

int main() {
    Geanta<std::string> ganta{"Ion"};      // crează geanta pentru Ion
    ganta = ganta + std::string{"haine"};  // adaugă obiect în geantă
    ganta + std::string{"pahar"};

    for (const auto& o : ganta) {  // iterează obiectele din geantă
        std::cout << o << "\n";    // afișează obiectele
    }

    return 0;
}
