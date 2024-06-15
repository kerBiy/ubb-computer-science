#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Cos {
   private:
    std::vector<T> items;

   public:
    void tipareste(std::ostream &out) {
        out << "Cos: ";
        for (const auto &item : items) {
            out << item << ' ';
        }
        out << '\n';
    }

    Cos &operator=(const Cos &cos) {
        if (this == &cos) {
            return *this;
        }

        this->items = cos.items;
        return *this;
    }

    Cos &operator+(const T &item) {
        items.push_back(item);
        return *this;
    }

    Cos &undo() {
        items.pop_back();
        return *this;
    }
};

int main() {
    Cos<std::string> cos;
    cos = cos + "Mere";
    cos + "Mere";
    cos = cos + "Paine" + "Lapte";
    cos.undo().undo();

    cos.tipareste(std::cout);
    return 0;
}