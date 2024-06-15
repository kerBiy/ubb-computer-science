#include <iostream>
#include <vector>

template <typename T>
class Adder {
   private:
    std::vector<T> operands;
    T sum;

   public:
    Adder(const T& item) : sum{item} {}
    Adder& operator=(const Adder& other) {
        if (this == &other) {
            return *this;
        }
        sum = other.sum;
        operands = other.operands;
        return *this;
    }
    Adder& operator+(const T& operand) {
        operands.push_back(operand);
        sum += operand;
        return *this;
    }
    Adder& operator--() {
        sum -= operands.back();
        operands.pop_back();
        return *this;
    }

    Adder operator--(int) {
        Adder temp = *this;
        sum -= operands.back();
        operands.pop_back();
        return temp;
    }
    T suma() { return sum; }
};

int main() {
    Adder<int> add{1};  // construim un adder,pornim cu valoarea 1
    add = add + 7 + 3;  // se adauga valorile 7 si 3
    add + 8;
    std::cout << add.suma() << "\n";  // tipareste suma (in acest caz:19)
    add--;
    // elimina ultimul termen adaugat
    std::cout << add.suma() << "\n";  // tipareste suma (in acest caz:11)
    --add--;
    std::cout << add.suma() << "\n";  // tipareste suma (in acest caz:1)

    int res = 11;
    // --res--;
    std::cout << res;
}