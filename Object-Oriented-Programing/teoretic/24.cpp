#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
class Measurement {
   private:
    T val;

   public:
    Measurement(const T& value) : val(value) {}

    T value() const { return this->val; }

    Measurement& operator+(const T& value) {
        val += value;
        return *this;
    }

    friend bool operator<(const Measurement& m1, const Measurement& m2) {
        return m1.value() < m2.value();
    }
};

int main() {
    // creaza un vector de masuratori cu valorile (10,2,3)
    std::vector<Measurement<int>> v{10, 2, 3};
    v[2] + 3 + 2;                   // aduna la masuratoarea 3 valuarea 5
    std::sort(v.begin(), v.end());  // sorteaza masuratorile
                                    // tipareste masuratorile
    //   (in acest caz: 2,8,10)
    for (const auto& m : v) std::cout << m.value() << ",";
    return 0;
}