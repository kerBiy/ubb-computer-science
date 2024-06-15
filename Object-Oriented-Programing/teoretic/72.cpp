// #include <iostream>
// using namespace std;
// class A {
//    public:
//     virtual void print() { cout << "printA" << endl; }
//     ~A() { cout << "~A" << endl; }
// };
// class B : public A {
//    public:
//     void print() { cout << "printB" << endl; }
//     virtual ~B() { cout << "~B" << endl; }
// };
// int main() {
//     A* o1 = new A();
//     A* o2 = new B();
//     o1->print();
//     o2->print();
//     delete o1;
//     delete o2;
//     return 0;
// }

#include <deque>
#include <iostream>
#include <string>
using namespace std;
int main() {
    deque<string> s;
    s.push_back("1");
    s.push_back("2");
    s.push_back("3");
    s.push_front("1");
    s.push_front("4");
    auto it = s.begin();
    auto end = s.end();
    end = end - 1;
    it++;
    while (it != end) {
        cout << *it;
        it++;
    }
    return 0;
}