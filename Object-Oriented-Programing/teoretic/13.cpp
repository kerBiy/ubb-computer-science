#include <cassert>
#include <exception>
#include <iostream>
#include <string>

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
   private:
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

int main() {
    Smoothy *sm = new SmoothyCuFrisca(
        new SmoothyCuUmbreluta(new BasicSmoothy(3, "nigger")));
    std::cout << sm->getPret() << ' ' << sm->descriere();
    delete sm;
}