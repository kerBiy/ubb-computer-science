#include <iostream>
#include <string>
#include <vector>

class Pizza {
   protected:
    int pret;

   public:
    Pizza(int pret) : pret(pret) {}
    virtual ~Pizza() = default;
    virtual std::string descriere() = 0;
    int getPret() { return pret; }
};

class BasicPizza : public Pizza {
   private:
    std::string denumire;

   public:
    BasicPizza(const std::string &denumire, int pret)
        : Pizza(pret), denumire{denumire} {}
    std::string descriere() override { return denumire; }
};

class PizzaCuPeperoni : public Pizza {
   private:
    Pizza *pizza;

   public:
    PizzaCuPeperoni(Pizza *p) : Pizza(p->getPret()), pizza(p) { pret += 2; }

    std::string descriere() override {
        return pizza->descriere() + " cu peperoni";
    }

    ~PizzaCuPeperoni() override { delete pizza; }
};

class PizzaCuCiuperci : public Pizza {
   private:
    Pizza *pizza;

   public:
    PizzaCuCiuperci(Pizza *p) : Pizza(p->getPret()), pizza(p) {
        pret += 3;
    }

    std::string descriere() override {
        return pizza->descriere() + " cu ciuperci";
    }

    ~PizzaCuCiuperci() override { delete pizza; }
};

std::vector<Pizza *> create() {
    std::vector<Pizza *> res;

    res.push_back(new PizzaCuCiuperci(new BasicPizza("Salami", 15)));
    res.push_back(new BasicPizza("Salami", 15));
    res.push_back(new PizzaCuCiuperci(
        new PizzaCuPeperoni(new BasicPizza("Diavola", 20))));

    return res;
}

int main() {
    auto vec = create();

    for (const auto &item : vec) {
        std::cout << item->descriere() << " - pret: " << item->getPret()
                  << '\n';
    }

    for (auto item : vec) {
        delete item;
    }

    return 0;
}