#include "Matrice.h"
#include "TestExtins.h"

#include <cassert>
#include <exception>

using namespace std;

void testCreeaza() {
    Matrice m(10, 10);
    assert(m.nrLinii() == 10);
    assert(m.nrColoane() == 10);
    for (int i = 0; i < m.nrLinii(); i++)
        for (int j = 0; j < m.nrColoane(); j++)
            assert(m.element(i, j) == NULL_TELEMENT);
}

void testAdauga() {
    Matrice m(10, 10);
    for (int j = 0; j < m.nrColoane(); j++)
        m.modifica(4, j, 3);
    for (int i = 0; i < m.nrLinii(); i++)
        for (int j = 0; j < m.nrColoane(); j++)
            if (i == 4)
                assert(m.element(i, j) == 3);
            else
                assert(m.element(i, j) == NULL_TELEMENT);
}

void testQuantity() {//scopul e sa adaugam multe date
    Matrice m(300, 300);
    for (int i = m.nrLinii() / 2; i < m.nrLinii(); i++) {
        for (int j = 0; j < m.nrColoane() / 2; j++) {
            int v1 = j;
            int v2 = m.nrColoane() - v1 - 1;
            if (i % 2 == 0 && v1 % 2 == 0)
                m.modifica(i, v1, i * v1);
            else if (v1 % 3 == 0)
                m.modifica(i, v1, i + v1);
            if (i % 2 == 0 && v2 % 2 == 0)
                m.modifica(i, v2, i * v2);
            else if (v2 % 3 == 0)
                m.modifica(i, v2, i + v2);
        }
    }
    for (int i = 0; i <= m.nrLinii() / 2; i++) {
        for (int j = 0; j < m.nrColoane() / 2; j++) {
            int v1 = j;
            int v2 = m.nrColoane() - v1 - 1;
            if (i % 2 == 0 && v1 % 2 == 0)
                m.modifica(i, v1, i * v1);
            else if (v1 % 3 == 0)
                m.modifica(i, v1, i + v1);
            if (i % 2 == 0 && v2 % 2 == 0)
                m.modifica(i, v2, i * v2);
            else if (v2 % 3 == 0)
                m.modifica(i, v2, i + v2);
        }
    }
    for (int i = 0; i < m.nrLinii(); i++)
        for (int j = 0; j < m.nrColoane(); j++)
            if (i % 2 == 0 && j % 2 == 0)
                assert(m.element(i, j) == i * j);
            else if (j % 3 == 0)
                assert(m.element(i, j) == i + j);
            else
                assert(m.element(i, j) == 0);
}

void testExceptii() {
    Matrice m(10, 10);
    try {
        m.element(-1, -1);
    }
    catch (exception &) {
        assert(true); //ar trebui sa arunce exceptie
    }
    try {
        m.modifica(12, 0, 1);
    }
    catch (exception &) {
        assert(true); //ar trebui sa arunce exceptie
    }
    try {
        assert(m.nrLinii());
    }
    catch (exception &) {
        assert(false); //nu ar trebui sa arunce exceptie
    }
}

void testTranspusa() {
    Matrice mat(3, 3);
    mat.modifica(0, 0, 1);
    mat.modifica(0, 1, 2);
    mat.modifica(0, 2, 3);
    mat.modifica(1, 0, 4);
    mat.modifica(1, 1, 5);
    mat.modifica(1, 2, 6);
    mat.modifica(2, 0, 7);
    mat.modifica(2, 1, 8);
    mat.modifica(2, 2, 9);

    mat.transpusa();

    assert(mat.nrLinii() == 3);
    assert(mat.nrColoane() == 3);
    assert(mat.element(0, 0) == 1);
    assert(mat.element(1, 0) == 2);
    assert(mat.element(2, 0) == 3);
    assert(mat.element(0, 1) == 4);
    assert(mat.element(1, 1) == 5);
    assert(mat.element(2, 1) == 6);
    assert(mat.element(0, 2) == 7);
    assert(mat.element(1, 2) == 8);
    assert(mat.element(2, 2) == 9);
}

void testAllExtins() {
    testCreeaza();
    testAdauga();
    testQuantity();
    testExceptii();
    testTranspusa();
}
