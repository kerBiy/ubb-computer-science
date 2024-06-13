#include <iostream>
#include <string>
#include <vector>

class Participant {
   public:
    virtual void tipareste() = 0;
    virtual bool eVoluntar() { return true; }
    virtual ~Participant() = default;
};

class Personal : public Participant {
   private:
    std::string name;

   public:
    Personal(const std::string &name) : name(name) {}
    void tipareste() override { std::cout << name; }
};

class Administrator : public Personal {
   public:
    Administrator(const std::string &name) : Personal(name) {}
    void tipareste() override {
        Personal::tipareste();
        std::cout << " Administrator\n";
    }
};

class Director : public Personal {
   public:
    Director(const std::string &name) : Personal(name) {}
    void tipareste() override {
        Personal::tipareste();
        std::cout << " Director\n";
    }
};

class Angajat : public Participant {
   private:
    Personal *p;

   public:
    Angajat(Personal *p) : p(p) {}
    void tipareste() override {
        p->tipareste();
        std::cout << " - angajat\n";
    }
    bool eVoluntar() override { return false; }
    ~Angajat() override { delete p; }
};

class ONG {
   private:
    std::vector<Participant *> items;

   public:
    ONG() = default;

    void add(Participant *p) { items.push_back(p); }

    void getAll(bool voluntar) {
        for (const auto &item : items) {
            if (item->eVoluntar() == voluntar) {
                item->tipareste();
            }
        }
    }

    ~ONG() {
        for (auto &item : items) {
            delete item;
        }
    }
};

ONG *create() {
    auto *res = new ONG;

    res->add(new Administrator("AdminVol"));
    res->add(new Angajat(new Administrator("AdminNev")));

    res->add(new Director("DirVol"));
    res->add(new Angajat(new Director("DirNev")));

    return res;
}

int main() {
    auto *ong = create();

    ong->getAll(true);
    std::cout << "Nigger\n";
    ong->getAll(false);

    delete ong;
    return 0;
}