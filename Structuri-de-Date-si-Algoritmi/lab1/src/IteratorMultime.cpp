#include "IteratorMultime.h"

#include "Multime.h"

IteratorMultime::IteratorMultime(const Multime &m) : mult(m) { prim(); }

TElem IteratorMultime::element() const { return mult.items[index]; }

bool IteratorMultime::valid() const { return index < mult.dim(); }

void IteratorMultime::urmator() { index += 1; }

void IteratorMultime::prim() { index = 0; }
