#include "TestScurt.h"
#include <cassert>

#include "MDO.h"
#include "IteratorMDO.h"

#include <vector>

using namespace std;

bool relatie1(TCheie cheie1, TCheie cheie2) {
    return cheie1 <= cheie2;
}

void testAll() {
    MDO dictOrd = MDO(relatie1);
    assert(dictOrd.dim() == 0);
    assert(dictOrd.vid());
    dictOrd.adauga(1, 2);
    dictOrd.adauga(1, 3);
    assert(dictOrd.dim() == 2);
    assert(!dictOrd.vid());
    vector<TValoare> v = dictOrd.cauta(1);
    assert(v.size() == 2);
    v = dictOrd.cauta(3);
    assert(v.size() == 0);
    IteratorMDO it = dictOrd.iterator();
    it.prim();
    while (it.valid()) {
        TElem e = it.element();
        it.urmator();
    }
    assert(dictOrd.sterge(1, 2) == true);
    assert(dictOrd.sterge(1, 3) == true);
    assert(dictOrd.sterge(2, 1) == false);
    assert(dictOrd.vid());

    // MY TESTS
    TElem keyPair1{3, 2};
    TElem keyPair2{1, 7};
    TElem keyPair3{7, 2};
    TElem keyPair4{23, 6};
    TElem keyPair5{15, 5};

    MDO dict{relatie1};

    dict.adauga(keyPair1.first, keyPair1.second);
    dict.adauga(keyPair2.first, keyPair2.second);
    dict.adauga(keyPair3.first, keyPair3.second);
    dict.adauga(keyPair4.first, keyPair4.second);
    dict.adauga(keyPair5.first, keyPair5.second);

    auto output = dict.inRange(2, 16);

    MDO correct_dict{relatie1};
    correct_dict.adauga(keyPair1.first, keyPair1.second);
    correct_dict.adauga(keyPair3.first, keyPair3.second);
    correct_dict.adauga(keyPair5.first, keyPair5.second);

    auto iter2 = correct_dict.iterator();

    for (auto elem: output) {
        auto correct_elem = iter2.element();
        assert(elem == correct_elem);
        iter2.urmator();
    }

    assert(!iter2.valid());
}

