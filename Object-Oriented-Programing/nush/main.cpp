#include <iostream>
#include <vector>
#include <cassert>

template<typename T>
class Expresie {
  private:
    std::string expr;

  public:
    explicit Expresie(const T &init_value) {
        expr += std::to_string(init_value);
    }

    Expresie &operator+(const T &new_value) {
        expr += "+" + std::to_string(new_value);
        return *this;
    }

    Expresie &operator-(const T &new_value) {
        expr += "-" + std::to_string(new_value);
        return *this;
    }

    Expresie &undo() {
        bool found = false;
        int pos;

        for (int i = 0; i < expr.size(); ++i) {
            if (expr[i] == '+' || expr[i] == '-') {
                found = true;
                pos = i;
            }
        }

        if (found) {
            int count = expr.size() - pos;

            for (int i = 0; i < count; ++i) {
                expr.pop_back();
            }
        }

        return *this;
    }

};

int main() {

    return 0;
}
