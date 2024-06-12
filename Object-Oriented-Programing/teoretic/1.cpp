#include <cassert>
#include <exception>
#include <iostream>
#include <string>

// Test

// 1 Specs
/// @brief Functia oglindeste un numar natural
/// @param x un numar intreg
/// @return returneaza oglinditul numarului x t...
/// @raises arunca std::exception daca numarul nu este strict pozitiv
// int f(int x) {
//     if (x <= 0) throw std::exception();

//     int rez = 0;
//     while (x) {
//         rez = rez * 10 + x % 10;
//         x /= 10;
//     }
//     return rez;
// }

// void testF() {
//     try {
//         f(-1);
//         assert(false);
//     } catch (const std::exception e) {
//     }

//     assert(f(1) == 1);
//     assert(f(21) == 12);
//     assert(f(121) == 121);
//     assert(f(123) == 321);

// }

// int main() {
//     testF();
//     std::cout << "All tests passed\n";

//     return 0;
// }

// #include <iostream>
// using namespace std;

// int except(bool thrEx) {
//     if (thrEx) {
//         throw 2;
//     }
//     return 3;
// }
// int main() {
//     try {
//         cout << except(1 < 1);
//         cout << except(true);
//         cout << except(false);
//     } catch (int ex) {
//         cout << ex;
//     }
//     cout << 4;
//     return 0;
// }

// 2 b)

// #include <iostream>
// using namespace std;
// class A {
//    public:
//     A() { cout << "A" << endl; }
//     ~A() { cout << "~A" << endl; }
//     void print() { cout << "print" << endl; }
// };
// void f() {
//     A a[2];
//     a[1].print();
// }
// int main() {
//     f();
//     return 0;
// }

class Smoothy {
   private:
    int pret;

   public:
    Smoothy(int price) : pret(price) {}
    virtual int getPret() { return pret; }
    virtual std::string descriere() = 0;
    virtual ~Smoothy() = default;
};

class BasicSmoothy : public Smoothy {
   private:
    std::string name;

   public:
    BasicSmoothy(int price, const std::string &name)
        : Smoothy(price), name(name) {}
    std::string descriere() override { return name; }
};

class DecoratorSmoothy : public Smoothy {
   protected:
    Smoothy *sm;

   public:
    DecoratorSmoothy(Smoothy *sm) : Smoothy(0), sm(sm) {}
    int getPret() override { return sm->getPret(); }
    std::string descriere() override { return sm->descriere(); }
    ~DecoratorSmoothy() override { delete sm; }
};

class SmoothyCuFrisca : public DecoratorSmoothy {
   public:
    SmoothyCuFrisca(Smoothy *sm) : DecoratorSmoothy(sm) {}
    int getPret() override { return DecoratorSmoothy::getPret() + 2; }
    std::string descriere() override {
        return DecoratorSmoothy::descriere() + " cu frisca";
    }
};

class SmoothyCuUmbreluta : public DecoratorSmoothy {
   public:
    SmoothyCuUmbreluta(Smoothy *sm) : DecoratorSmoothy(sm) {}

    int getPret() override { return DecoratorSmoothy::getPret() + 3; }
    std::string descriere() override {
        return DecoratorSmoothy::descriere() + " cu umbreluta";
    }
};

// std::vector<Smoothy *> func() {}

int main() {
    Smoothy *sm = new SmoothyCuFrisca(
        new SmoothyCuUmbreluta(new BasicSmoothy(3, "nigger")));
    std::cout << sm->getPret() << sm->descriere();
    delete sm;
}