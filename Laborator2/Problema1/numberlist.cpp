#include "numberlist.h"
#include <iostream>

void NumberList::Init() 
{
    count = 0;
}

bool NumberList::Add(int x)
{
    if (count + 1 >= 10) return false;
    numbers[count++] = x;
    return true;
}

void NumberList::Sort()
{
    // Simple sorting algorithm.
    int aux;
    for (int i = 0; i < count - 1; i++)
	for (int j = i + 1; j < count; j++)
	     if (numbers[i] > numbers[j]) {
		aux = numbers[i];
		numbers[i] = numbers[j];
		numbers[j] = aux;
	     }
}

void NumberList::Print()
{
    for (int i = 0; i < count; i++)
	std::cout << numbers[i] << " ";
    std::cout << "\n";
}

bool NumberList::Insert(int pozitie, int x)
{
    if (count + 1 >= 10) return false;
    for (int i = ++count; i > pozitie; i--)
	numbers[i] = numbers[i - 1];
    numbers[pozitie] = x;
    return true;
}

void NumberList::RemoveNumber(int x)
{
    int i = 0;
    while (i < count) {
	if (numbers[i] == x) {
	    for (int j = i; j < count - 1; j++)
		numbers[j] = numbers[j + 1];
	    count--;
	} else i++;
    }
}

void NumberList::SetCount(int count)
{
    this->count = count;
}
