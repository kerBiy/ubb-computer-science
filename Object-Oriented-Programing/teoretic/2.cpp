// test 2
#include <iostream>
#include <string>

class Meniu {
   private:
    int pret;

   public:
    Meniu(int pret) : pret(pret) {}
    virtual std::string descriere() = 0;
    virtual int getPret() { return pret; }
};

class MicDejun : public Meniu {
   private:
    std::string denumire;

   public:
    MicDejun(const std::string &denumire)
        : Meniu(!(denumire == "Ochiuri" || denumire == "Omleta") ? -99999
                : denumire == "Ochiuri"                          ? 10
                                                                 : 15),
          denumire(denumire) {}

    std::string descriere() override { return denumire; }
};

class CuRacoritoare : public Meniu {
   private:
    Meniu *m;

   public:
    CuRacoritoare(Meniu *m) : Meniu(0), m(m) {}
    std::string descriere() { return m->descriere() + " cu recoritoare"; }
    int getPret() { return m->getPret() + 4; }
};

class CuCafea : public Meniu {
   private:
    Meniu *m;

   public:
    CuCafea(Meniu *m) : Meniu(0), m(m) {}
    std::string descriere() { return m->descriere() + " cu cafea"; }
    int getPret() { return m->getPret() + 5; }
};

int main() {
    Meniu *m = new CuCafea(new CuRacoritoare(new MicDejun("ush")));
    std::cout << m->descriere() << m->getPret();

    delete m;
    return 0;
}