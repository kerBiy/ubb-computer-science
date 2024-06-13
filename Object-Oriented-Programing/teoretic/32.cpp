// #include <iostream>
// using namespace std;

// class A {
//    public:
//     A() { cout << "A()" << endl; }
//     void print() { cout << "printA" << endl; }
// };
// class B : public A {
//    public:
//     B() { cout << "B()" << endl; }
//     void print() { cout << "printB" << endl; }
// };

// int main() {
//     A* o1 = new A();
//     B* o2 = new B();
//     o1->print();
//     o2->print();
//     delete o1;
//     delete o2;
//     return 0;
// }

// 2 b(0.5p)
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(5);
    v.push_back(7);
    v[0] = 6;
    v.push_back(8);
    auto it = v.begin();
    it = it + 1;
    while (it != v.end()) {
        cout << *it << endl;
        it++;
    }
}