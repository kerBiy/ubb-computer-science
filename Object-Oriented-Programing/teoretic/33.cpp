#include <algorithm>
#include <iostream>
#include <vector>

class Transformer {
   public:
    Transformer() = default;
    virtual ~Transformer() = default;
    virtual void transform(std::vector<int> &nrs) = 0;
};

class Swapper : public Transformer {
   public:
    void transform(std::vector<int> &nrs) override {
        for (size_t i = 0; i < nrs.size() - 1; i += 2) {
            std::swap(nrs[i], nrs[i + 1]);
        }
    }
};

class Adder : public Transformer {
   private:
    int cat;

   public:
    Adder(int cat) : cat(cat) {}
    void transform(std::vector<int> &nrs) override {
        for (int &nr : nrs) {
            nr += cat;
        }
    }
};

class Nuller : public Adder {
   public:
    Nuller(int cat) : Adder(cat) {}

    void transform(std::vector<int> &nrs) override {
        Adder::transform(nrs);
        for (int &nr : nrs) {
            if (nr > 10) {
                nr = 0;
            }
        }
    }
};

class Composite : public Transformer {
   private:
    Transformer *t1;
    Transformer *t2;

   public:
    Composite(Transformer *t1, Transformer *t2) : t1(t1), t2(t2) {}

    void transform(std::vector<int> &nrs) override {
        t1->transform(nrs);
        t2->transform(nrs);
    }

    ~Composite() override {
        delete t1;
        delete t2;
    }
};

class Numbers {
   private:
    std::vector<int> nrs;
    Transformer *t;

   public:
    Numbers(Transformer *t) : t(t) {}

    void add(int nr) { nrs.push_back(nr); }

    std::vector<int> transform() {
        std::sort(nrs.begin(), nrs.end(),
                  [](int n1, int n2) { return n1 > n2; });

        t->transform(nrs);
        return nrs;
    }

    ~Numbers() { delete t; }
};

Numbers *create() {
    auto *res = new Numbers(new Composite(
        new Nuller(9), new Composite(new Swapper(), new Adder(3))));
    return res;
}

int main() {
    auto *nr1 = create();
    for (int i = 1; i <= 5; ++i) {
        nr1->add(i);
    }

    auto res = nr1->transform();
    for (const auto &nr : res) {
        std::cout << nr << " ";
    }

    delete nr1;
    return 0;
}