// 2 a (1p)
#include <iostream>
#include <vector>
class A {
   public:
    A() { std::cout << "A"; }
    virtual void print() { std::cout << "A"; }
    virtual ~A() { std::cout << "~A"; }
};
class B : public A {
   public:
    B() { std::cout << "B"; }
    void print() override { std::cout << "B"; }
    ~B() { std::cout << "~B"; }
};
int main() {
    std::vector<A*> v;
    auto a = A{};
    auto b = B{};
    v.push_back(&a);
    v.push_back(&b);
    std::cout << "\n";

    for (auto& el : v) el->print();

    std::cout << "\n";
    for (auto& el : v) delete el;
    return 0;
}