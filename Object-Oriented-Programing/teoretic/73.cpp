#include <iostream>
#include <vector>

class Fruct {
   public:
    virtual void tipareste() = 0;
    virtual bool eCuSamburi() { return false; }
    virtual ~Fruct() = default;
};

class Pepene : public Fruct {
   private:
    float kg;

   public:
    Pepene(float kg) : kg(kg) {}
    void tipareste() override { std::cout << kg << "kg - pepene"; }
};

class PepeneRosu : public Pepene {
   public:
    PepeneRosu(float kg) : Pepene(kg) {}
    void tipareste() override {
        Pepene::tipareste();
        std::cout << " rosu";
    }
};

class PepeneGalben : public Pepene {
   public:
    PepeneGalben(float kg) : Pepene(kg) {}
    void tipareste() override {
        Pepene::tipareste();
        std::cout << " galben";
    }
};

class CuSamburi : public Fruct {
   private:
    Fruct *fruct;

   public:
    CuSamburi(Fruct *fruct) : fruct(fruct) {}
    bool eCuSamburi() override { return true; }
    void tipareste() override {
        fruct->tipareste();
        std::cout << " cu samburi";
    }
    ~CuSamburi() override { delete fruct; }
};

class Cos {
   private:
    std::vector<Fruct *> items;

   public:
    ~Cos() {
        for (auto item : items) {
            delete item;
        }
    }

    void add(Fruct *fruct) { items.push_back(fruct); }

    std::vector<Fruct *> getAll(bool cuSamburi) {
        std::vector<Fruct *> res;

        for (const auto &item : items) {
            if (item->eCuSamburi() == cuSamburi) {
                res.push_back(item);
            }
        }

        return res;
    }
};

Cos *create() {
    auto *res = new Cos;

    res->add(new PepeneRosu(5.14));
    res->add(new CuSamburi(new PepeneGalben(2.47)));
    res->add(new PepeneGalben(2.14));
    res->add(new CuSamburi(new PepeneRosu(6.14)));

    return res;
}

int main() {
    auto *cos = create();

    for (const auto &item : cos->getAll(true)) {
        item->tipareste();
        std::cout << "\n";
    }
    std::cout << "\nAlea fara samburi:\n";

    for (const auto &item : cos->getAll(false)) {
        item->tipareste();
        std::cout << "\n";
    }

    delete cos;
    return 0;
}