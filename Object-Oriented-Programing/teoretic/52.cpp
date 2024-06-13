// 2 a (1p)
#include <iostream>
#include <vector>

class A {
   public:
    A() { std::cout << "A"; }
    virtual void print() { std::cout << "printA"; }
};
class B : public A {
   public:
    B() { std::cout << "B"; }
    virtual void print() { std::cout << "printB"; }
};
int main() {
    std::vector<A> v;
    A a;
    B b;
    v.push_back(a);
    v.push_back(b);
    for (auto e : v) {
        e.print();
    }
    return 0;
}