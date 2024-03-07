#include "../include/Multime.h"
#include "../include/IteratorMultime.h"

// o posibila relatie
bool rel(TElem e1, TElem e2)
{
	return e1 <= e2;
}

Multime::Multime()
{
	capacity = 10;
	size = 0;
	items = new TElem[capacity];
}

Multime::~Multime()
{
	delete[] items;
}

void Multime::resize_append()
{
	capacity *= 2;
	TElem *new_items = new TElem[capacity];
	for (int i = 0; i < size; ++i)
		new_items[i] = items[i];

	delete[] items;
	items = new_items;
}

void Multime::resize_delete()
{
	capacity /= 2;
	TElem *new_items = new TElem[capacity];
	for (int i = 0; i < size; ++i)
		new_items[i] = items[i];

	delete[] items;
	items = new_items;
}

bool Multime::adauga(TElem elem)
{
	if (cauta(elem))
		return false;

	if (size == capacity)
		resize_append();

	int poz = size - 1;

	while (!rel(items[poz], elem) && poz >= 0)
	{
		items[poz + 1] = items[poz];
		poz--;
	}

	items[poz + 1] = elem;
	size++;

	return true;
}

bool Multime::sterge(TElem elem)
{
	if (!cauta(elem))
		return false;

	if (size == capacity / 4)
		resize_delete();

	int poz;
	for (int i = 0; i < size; ++i)
		if (items[i] == elem)
			poz = i;

	for (int i = poz; i < size; ++i)
		items[i] = items[i + 1];

	size--;

	return true;
}

bool Multime::cauta(TElem elem) const
{
	for (int i = 0; i < size; ++i)
		if (items[i] == elem)
			return true;
	return false;
}

int Multime::dim() const
{
	return size;
}

bool Multime::vida() const
{
	return size == 0;
}

IteratorMultime Multime::iterator() const
{
	return IteratorMultime(*this);
}
