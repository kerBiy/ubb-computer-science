// #include <iostream>
// using namespace std;

// int except(int v) {
//     if (v < 0) {
//         throw 1;
//     } else if (v > 0) {
//         throw exception();
//     }
//     return 0;
// }
// int main() {
//     try {
//         cout << except(1 < 1);
//         cout << except(-5);
//         cout << except(5);
//     } catch (std::exception& e) {
//         cout << "A";
//     } catch (int x) {
//         cout << "B";
//     }
//     cout << "C";
//     return 0;
// }

#include <iostream>
using namespace std;
class A {
    int x;

   public:
    A(int x) : x{x} {}

    void print() { cout << x << ","; }
};

A f(A a) {
    a.print();
    a = A{7};
    a.print();
    return a;
}

int main() {
    A a{5};
    a.print();
    f(a);
    a.print();
}