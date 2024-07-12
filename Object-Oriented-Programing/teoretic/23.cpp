#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Meniu {
   protected:
    int pret;

   public:
    virtual ~Meniu() {}
    virtual std::string descriere() const = 0;
    int getPret() const { return pret; }
};

class CuRacoritoare : public Meniu {
   private:
    Meniu* meniu;

   public:
    CuRacoritoare(Meniu* m) : meniu(m) { pret = meniu->getPret() + 4; }
    ~CuRacoritoare() { delete meniu; }
    std::string descriere() const override {
        return meniu->descriere() + " cu racoritoare";
    }
};

class CuCafea : public Meniu {
   private:
    Meniu* meniu;

   public:
    CuCafea(Meniu* m) : meniu(m) { pret = meniu->getPret() + 5; }
    ~CuCafea() { delete meniu; }
    std::string descriere() const override {
        return meniu->descriere() + " cu cafea";
    }
};

class MicDejun : public Meniu {
   private:
    std::string denumire;

   public:
    MicDejun(const std::string& den, int p) : denumire(den) { pret = p; }
    std::string descriere() const override { return denumire; }
};

std::vector<Meniu*> createMenus() {
    std::vector<Meniu*> menus;

    menus.push_back(new CuCafea(new CuRacoritoare(new MicDejun("Omleta", 15))));
    menus.push_back(new CuCafea(new MicDejun("Ochiuri", 10)));
    menus.push_back(new MicDejun("Omleta", 15));

    return menus;
}

int main() {
    std::vector<Meniu*> menus = createMenus();

    std::sort(menus.begin(), menus.end(),
              [](Meniu* a, Meniu* b) { return a->getPret() > b->getPret(); });

    for (const auto& menu : menus) {
        std::cout << menu->descriere() << " - Pret: " << menu->getPret()
                  << " RON" << std::endl;
    }

    for (auto& menu : menus) {
        delete menu;
    }

    return 0;
}
