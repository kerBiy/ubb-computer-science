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
    double kg;

   public:
    Pepene(double kg) : kg(kg) {}
    void tipareste() override { std::cout << kg << "kg pepene"; }
};

class PepeneRosu : public Pepene {
   public:
    PepeneRosu(double kg) : Pepene(kg) {}
    void tipareste() override {
        Pepene::tipareste();
        std::cout << " rosu";
    }
};

class PepeneGalben : public Pepene {
   public:
    PepeneGalben(double kg) : Pepene(kg) {}
    void tipareste() override {
        Pepene::tipareste();
        std::cout << " galben";
    }
};

class CuSamburi : public Fruct {
   private:
    Fruct *f;

   public:
    CuSamburi(Fruct *fruct) : f(fruct) {}
    void tipareste() override {
        f->tipareste();
        std::cout << " cu samburi";
    }
    bool eCuSamburi() override { return true; }
    ~CuSamburi() override { delete f; }
};

class Cos {
   private:
    std::vector<Fruct *> items;

   public:
    void add(Fruct *fruct) { items.push_back(fruct); }
    std::vector<Fruct *> getAll(bool cuSamburi) {
        std::vector<Fruct *> res;

        for (auto fruit : items) {
            if (fruit->eCuSamburi() == cuSamburi) {
                res.push_back(fruit);
            }
        }

        return res;
    }
    ~Cos() {
        for (auto fruit : items) {
            delete fruit;
        }
    }
};

Cos create() {
    Cos res;

    res.add(new PepeneRosu(2));
    res.add(new CuSamburi(new PepeneGalben(1.5)));
    res.add(new PepeneGalben(1));
    res.add(new CuSamburi(new PepeneRosu(3.5)));

    return res;
}

int main() {
    auto cos = create();

    std::cout << "Fructele cu samburi:\n";
    auto cuSamburi = cos.getAll(true);
    for (auto fruit : cuSamburi) {
        fruit->tipareste(); 
        std::cout << "\n";
    }

    std::cout << "\nFructele fara smaburi:\n";
    auto faraSamburi = cos.getAll(false);
    for (auto fruit : faraSamburi) {
        fruit->tipareste(); 
        std::cout << "\n";
    }

    return 0;
}